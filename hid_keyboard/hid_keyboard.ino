/*********************************************************************
  This is an example for our nRF52 based Bluefruit LE modules

  Pick one up today in the adafruit shop!

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  MIT license, check LICENSE for more information
  All text above, and the splash screen below must be included in
  any redistribution
*********************************************************************/
#include <bluefruit.h>

BLEDis bledis;
BLEHidAdafruit blehid;

bool hasKeyPressed = false;

# define MAX_COLUMNS 8
int COLUMNS[] = {PIN_A0, PIN_A3, PIN_A4, 12, 14, 16, 20, 27};

#define MAX_ROWS 11
int ROWS[] = {PIN_A1, PIN_A2, PIN_A5, 13, 8, 15, 7, 11, 26, 25, 6};

#define KEY_MENU HID_KEY_A
#define KEY_ESC HID_KEY_A
#define KEY_FN HID_KEY_A
#define KEY_CTRL HID_KEY_A

static uint8_t CHARACTER_MAP[9][11] = {
  {0,                   HID_KEY_Z,           HID_KEY_H,          HID_KEY_TAB, HID_KEY_1, HID_KEY_U,      HID_KEY_Q, HID_KEY_7,          0,      KEY_MENU, KEY_ESC},
  {HID_KEY_SPACE,       HID_KEY_X,           HID_KEY_J,          HID_KEY_A,   HID_KEY_2, HID_KEY_I,      HID_KEY_W, HID_KEY_8,          KEY_FN, 0,        0},
  {HID_KEY_ARROW_UP,    HID_KEY_C,           HID_KEY_K,          HID_KEY_S,   HID_KEY_3, HID_KEY_O,      HID_KEY_E, HID_KEY_9,          0,      0,        0},
  {HID_KEY_COMMA,       HID_KEY_V,           HID_KEY_M,          HID_KEY_D,   HID_KEY_4, HID_KEY_P,      HID_KEY_R, HID_KEY_0,          0,      0,        0},
  {HID_KEY_ARROW_LEFT,  HID_KEY_B,           HID_KEY_PERIOD,     HID_KEY_F,   HID_KEY_5, HID_KEY_L,      HID_KEY_T, HID_KEY_BACKSPACE,  0,      0,        0},
  {HID_KEY_ARROW_RIGHT, HID_KEY_N,           HID_KEY_ARROW_DOWN, HID_KEY_G,   HID_KEY_6, HID_KEY_RETURN, HID_KEY_Y, HID_KEY_APOSTROPHE, 0,      0,        0},
  {HID_KEY_SHIFT_LEFT,  0,                   0,                  0,           0,         0,              0,         0,                  0,      0,        0},
  {0,                   HID_KEY_SHIFT_RIGHT, 0,                  KEY_CTRL,    0,         0,              0,         0,                  0,      0,        0},
  {0,                   0,                   0,                  KEY_CTRL,    0,         0,              0,         0,                  0,      0,        0},
};

static uint8_t keyboardState[9][11] = { 0 };
static bool shiftPressed = false;

void sendKey(uint8_t keyCode, bool down) {

  // TODO: Consider whether we need to do some shift handling locally.
  if (keyCode == HID_KEY_SHIFT_LEFT ||
      keyCode == HID_KEY_SHIFT_RIGHT) {
    shiftPressed = down;
    return;
  }
  
  if (down) {
    blehid.keyboardReport(shiftPressed ? KEYBOARD_MODIFIER_LEFTSHIFT : 0, keyCode);
  } else {
    blehid.keyRelease();
  }
}

void setup()
{
  Serial.begin(115200);

  Serial.println("Bluefruit52 HID Keyboard Example");
  Serial.println("--------------------------------\n");

  Serial.println();
  Serial.println("Go to your phone's Bluetooth settings to pair your device");
  Serial.println("then open an application that accepts keyboard input");

  Serial.println();
  Serial.println("Enter the character(s) to send:");
  Serial.println();

  Bluefruit.begin();
  // Set max power. Accepted values are: -40, -30, -20, -16, -12, -8, -4, 0, 4
  Bluefruit.setTxPower(4);
  Bluefruit.setName("Bluefruit52");

  // Configure and Start Device Information Service
  bledis.setManufacturer("Adafruit Industries");
  bledis.setModel("Bluefruit Feather 52");
  bledis.begin();

  /* Start BLE HID
     Note: Apple requires BLE device must have min connection interval >= 20m
     ( The smaller the connection interval the faster we could send data).
     However for HID and MIDI device, Apple could accept min connection interval
     up to 11.25 ms. Therefore BLEHidAdafruit::begin() will try to set the min and max
     connection interval to 11.25  ms and 15 ms respectively for best performance.
  */
  blehid.begin();

  /* Set connection interval (min, max) to your perferred value.
     Note: It is already set by BLEHidAdafruit::begin() to 11.25ms - 15ms
     min = 9*1.25=11.25 ms, max = 12*1.25= 15 ms
  */
  /* Bluefruit.setConnInterval(9, 12); */

  // Set up and start advertising
  startAdv();

  // Initialize the GPIO pins.

  for (int c = 0; c < MAX_COLUMNS; c++) {
    pinMode(COLUMNS[c], INPUT_PULLUP);
  }

  for (int r = 0; r < MAX_ROWS; r++) {
    pinMode(ROWS[r], INPUT_PULLUP);
  }

}

void startAdv(void)
{
  // Advertising packet
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_KEYBOARD);

  // Include BLE HID service
  Bluefruit.Advertising.addService(blehid);

  // There is enough room for the dev name in the advertising packet
  Bluefruit.Advertising.addName();

  /* Start Advertising
     - Enable auto advertising if disconnected
     - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
     - Timeout for fast mode is 30 seconds
     - Start(timeout) with timeout = 0 will advertise forever (until connected)

     For recommended advertising interval
     https://developer.apple.com/library/content/qa/qa1931/_index.html
  */
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
  Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
  Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds
}

void loop()
{
  // Only send KeyRelease if previously pressed to avoid sending
  // multiple keyRelease reports (that consume memory and bandwidth)
  if ( hasKeyPressed )
  {
    hasKeyPressed = false;
    blehid.keyRelease();

    // Delay a bit after a report
    delay(5);
  }

  if (Serial.available())
  {
    char ch = (char) Serial.read();

    // echo
    Serial.write(ch);

    blehid.keyPress(ch);
    hasKeyPressed = true;

    // Delay a bit after a report
    delay(5);
  }

  // Iterate over the columns, pulling each low in turn.
  for (int c = 0; c < MAX_COLUMNS; c++) {
    int column = COLUMNS[c];

    // Pull the column low.
    pinMode(column, OUTPUT);
    digitalWrite(column, LOW);
    delay(5); // TODO: Is this necessary

    // TODO: Consider delaying here to allow everything to become quiescent.

    // Iterate over the rows, reading their state.
    for (int r = 0; r < MAX_ROWS; r++) {
      
      int keyDown = (digitalRead(ROWS[r]) == LOW) ? 1 : 0;
      int currentKeyDown = keyboardState[c][r];
      
      if (keyDown != currentKeyDown) {
        char character = CHARACTER_MAP[c][r];
        if (character != HID_KEY_NONE) {
          sendKey(character, keyDown);
          keyboardState[c][r] = keyDown;
        }
      }
    }

    // Restore the column.
    pinMode(column, INPUT_PULLUP);
    delay(5); // TODO: Is this necessary
  }

  // Request CPU to enter low-power mode until an event/interrupt occurs
  waitForEvent();
}

/**
   RTOS Idle callback is automatically invoked by FreeRTOS
   when there are no active threads. E.g when loop() calls delay() and
   there is no bluetooth or hw event. This is the ideal place to handle
   background data.

   NOTE: FreeRTOS is configured as tickless idle mode. After this callback
   is executed, if there is time, freeRTOS kernel will go into low power mode.
   Therefore waitForEvent() should not be called in this callback.
   http://www.freertos.org/low-power-tickless-rtos.html

   WARNING: This function MUST NOT call any blocking FreeRTOS API
   such as delay(), xSemaphoreTake() etc ... for more information
   http://www.freertos.org/a00016.html
*/
void rtos_idle_callback(void)
{
  // Don't call any other FreeRTOS blocking API()
  // Perform background task(s) here
}
