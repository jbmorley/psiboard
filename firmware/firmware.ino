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

# define MAX_COLUMNS 11
int COLUMNS[] = {PIN_A5, PIN_A1, PIN_A0, 16, 15, 7, 11, 30, 25, 27, 26};
#define MAX_ROWS 8
int ROWS[] = {6, 8, 14, 13, 12, PIN_A4, PIN_A3, PIN_A2};

#define KEY_NONE HID_KEY_A

#define COL_COUNT 11
#define ROW_COUNT 8

static uint8_t CHARACTER_MAP[COL_COUNT][ROW_COUNT] = {
  { KEY_NONE,            HID_KEY_Z,           HID_KEY_H,          HID_KEY_TAB,          HID_KEY_1, HID_KEY_U,        HID_KEY_Q,      HID_KEY_7           },
  { HID_KEY_SPACE,       HID_KEY_X,           HID_KEY_J,          HID_KEY_A,            HID_KEY_2, HID_KEY_I,        HID_KEY_W,      HID_KEY_8,          },
  { HID_KEY_ARROW_UP,    HID_KEY_C,           HID_KEY_K,          HID_KEY_S,            HID_KEY_3, HID_KEY_O,        HID_KEY_E,      HID_KEY_9,          },
  { HID_KEY_COMMA,       HID_KEY_V,           HID_KEY_M,          HID_KEY_D,            HID_KEY_4, HID_KEY_P,        HID_KEY_R,      HID_KEY_0,          },
  { HID_KEY_ARROW_LEFT,  HID_KEY_B,           HID_KEY_PERIOD,     HID_KEY_F,            HID_KEY_5, HID_KEY_L,        HID_KEY_T,      HID_KEY_BACKSPACE,  },
  { HID_KEY_ARROW_RIGHT, HID_KEY_N,           HID_KEY_ARROW_DOWN, HID_KEY_G,            HID_KEY_6, HID_KEY_RETURN,   HID_KEY_Y,      HID_KEY_APOSTROPHE, },
  { HID_KEY_SHIFT_LEFT,  KEY_NONE,            KEY_NONE,           KEY_NONE,             KEY_NONE,  KEY_NONE,         KEY_NONE,       KEY_NONE,           },
  { KEY_NONE,            HID_KEY_SHIFT_RIGHT, KEY_NONE,           KEY_NONE,             KEY_NONE,  KEY_NONE,         KEY_NONE,       KEY_NONE,           },
  { KEY_NONE,            KEY_NONE,            HID_KEY_ALT_LEFT,   HID_KEY_CONTROL_LEFT, KEY_NONE,  KEY_NONE,         KEY_NONE,       KEY_NONE,           },
  { KEY_NONE,            KEY_NONE,            KEY_NONE,           KEY_NONE,             KEY_NONE,  HID_KEY_GUI_LEFT, KEY_NONE,       KEY_NONE,           },
  { KEY_NONE,            KEY_NONE,            KEY_NONE,           KEY_NONE,             KEY_NONE,  KEY_NONE,         HID_KEY_ESCAPE, KEY_NONE,           },
};

typedef enum {
  EventTypeKey,
  EventTypeCharacter,
  EventTypeConsumerKey,
} EventType;

struct Event {
  EventType type;
  uint16_t data;
};

struct ModifierBehavior {
  uint8_t modifiers;
  uint8_t keyCode;
  Event event;
};

#define SHIFT_BEHAVIOR_COUNT 25
static ModifierBehavior ShiftBehavior[SHIFT_BEHAVIOR_COUNT] = {
  { .modifiers = KEYBOARD_MODIFIER_LEFTSHIFT | KEYBOARD_MODIFIER_RIGHTSHIFT, .keyCode = HID_KEY_COMMA,       .event = { .type = EventTypeKey,         .data = HID_KEY_SLASH } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTSHIFT | KEYBOARD_MODIFIER_RIGHTSHIFT, .keyCode = HID_KEY_PERIOD,      .event = { .type = EventTypeCharacter,   .data = '?'           } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTSHIFT | KEYBOARD_MODIFIER_RIGHTSHIFT, .keyCode = HID_KEY_APOSTROPHE,  .event = { .type = EventTypeCharacter,   .data = '~'           } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTSHIFT | KEYBOARD_MODIFIER_RIGHTSHIFT, .keyCode = HID_KEY_2,           .event = { .type = EventTypeCharacter,   .data = '"'           } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_Y,           .event = { .type = EventTypeKey,         .data = HID_KEY_KEYPAD_MULTIPLY                 } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_U,           .event = { .type = EventTypeKey,         .data = HID_KEY_KEYPAD_DIVIDE                   } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_I,           .event = { .type = EventTypeKey,         .data = HID_KEY_KEYPAD_ADD                      } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_O,           .event = { .type = EventTypeKey,         .data = HID_KEY_KEYPAD_SUBTRACT                 } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_P,           .event = { .type = EventTypeKey,         .data = HID_KEY_KEYPAD_EQUAL                    } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_1,           .event = { .type = EventTypeCharacter,   .data = '_'                                     } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_2,           .event = { .type = EventTypeCharacter,   .data = '#'                                     } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_3,           .event = { .type = EventTypeKey,         .data = HID_KEY_BACKSLASH                       } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_4,           .event = { .type = EventTypeCharacter,   .data = '@'                                     } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_5,           .event = { .type = EventTypeCharacter,   .data = '<'                                     } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_6,           .event = { .type = EventTypeCharacter,   .data = '>'                                     } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_7,           .event = { .type = EventTypeKey,         .data = HID_KEY_BRACKET_LEFT                    } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_8,           .event = { .type = EventTypeKey,         .data = HID_KEY_BRACKET_RIGHT                   } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_9,           .event = { .type = EventTypeCharacter,   .data = '{'                                     } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_0,           .event = { .type = EventTypeCharacter,   .data = '}'                                     } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_L,           .event = { .type = EventTypeCharacter,   .data = ';'                                     } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_APOSTROPHE,  .event = { .type = EventTypeCharacter,   .data = ':'                                     } },
//  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_ARROW_LEFT,  .event = { .type = EventTypeKey,         .data = HID_KEY_HOME                            } },
//  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_ARROW_RIGHT, .event = { .type = EventTypeKey,         .data = HID_KEY_END                             } },
//  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_ARROW_UP,    .event = { .type = EventTypeKey,         .data = HID_KEY_PAGE_UP                         } },
//  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_ARROW_DOWN,  .event = { .type = EventTypeKey,         .data = HID_KEY_PAGE_DOWN                       } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_TAB,         .event = { .type = EventTypeKey,         .data = HID_KEY_CAPS_LOCK                       } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_M,           .event = { .type = EventTypeConsumerKey, .data = HID_USAGE_CONSUMER_BRIGHTNESS_DECREMENT } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_PERIOD,      .event = { .type = EventTypeConsumerKey, .data = HID_USAGE_CONSUMER_BRIGHTNESS_INCREMENT } },
  { .modifiers = KEYBOARD_MODIFIER_LEFTALT,                                  .keyCode = HID_KEY_ESCAPE,      .event = { .type = EventTypeConsumerKey, .data = HID_USAGE_CONSUMER_POWER                } },
};

static uint8_t keyboardState[COL_COUNT][ROW_COUNT] = { 0 };

static uint8_t modifierState = 0;

void updateModifierState(uint8_t *modifierState, uint8_t modifier, bool down) {
  if (down) {
    *modifierState |= modifier;
  } else {
    *modifierState &= ~modifier;
  }
}

void sendEvent(Event event, bool down) {
  if (event.type == EventTypeKey) {
    if (down) {
      blehid.keyboardReport(0, event.data);
    } else {
      blehid.keyRelease();
    }
  } else if (event.type == EventTypeCharacter) {
    if (down) {
      blehid.keyPress(event.data);
    } else {
      blehid.keyRelease();
    }
  } else if (event.type == EventTypeConsumerKey) {
    if (down) { 
      blehid.consumerKeyPress(event.data);
    } else {
      blehid.consumerKeyRelease();
    }
  }
}

void sendKey(uint8_t keyCode, bool down) {

  if (keyCode == HID_KEY_SHIFT_LEFT) {
    updateModifierState(&modifierState, KEYBOARD_MODIFIER_LEFTSHIFT, down);
    return;
  }

  if (keyCode == HID_KEY_SHIFT_RIGHT) {
    updateModifierState(&modifierState, KEYBOARD_MODIFIER_RIGHTSHIFT, down);
    return;
  }

  if (keyCode == HID_KEY_ALT_LEFT) {
    updateModifierState(&modifierState, KEYBOARD_MODIFIER_LEFTALT, down);
    return;
  }

  if (keyCode == HID_KEY_GUI_LEFT) {
    updateModifierState(&modifierState, KEYBOARD_MODIFIER_LEFTGUI, down);
    return;
  }

  if (keyCode == HID_KEY_CONTROL_LEFT) {
    updateModifierState(&modifierState, KEYBOARD_MODIFIER_LEFTCTRL, down);
    return;
  }

  if (modifierState > 0) {
    ModifierBehavior behavior;
    bool found = false;
    for (int i = 0; i < SHIFT_BEHAVIOR_COUNT; i++) {
      ModifierBehavior loopBehavior = ShiftBehavior[i];
      if ((modifierState & loopBehavior.modifiers) &&
          (loopBehavior.keyCode == keyCode)) {
        behavior = loopBehavior;
        found = true;
        break;
      }
    }
    if (found) {
      sendEvent(behavior.event, down);
      return;
    }
  }
  
  if (down) {
    blehid.keyboardReport(modifierState, keyCode);
  } else {
    blehid.keyRelease();
  }
}

void setup()
{
  Bluefruit.begin();
  // Set max power. Accepted values are: -40, -30, -20, -16, -12, -8, -4, 0, 4
  Bluefruit.setTxPower(4);
  Bluefruit.setName("Psion Keyboard");

  // Configure and Start Device Information Service
  bledis.setManufacturer("InSeven Limited");
  bledis.setModel("Psion Keyboard");
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
