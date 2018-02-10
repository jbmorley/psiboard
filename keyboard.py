#!/usr/bin/env python3

import RPi.GPIO as GPIO


BUS = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 16, 17, 18, 19, 20, 21, 22, 23]
COLUMNS = [:11]
ROWS = [11:]


GPIO.setmode(GPIO.BCM)

GPIO.setup(COLUMNS[0], GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(COLUMNS[1], GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(COLUMNS[2], GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(COLUMNS[3], GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(COLUMNS[4], GPIO.IN, pull_up_down=GPIO.PUD_DOWN) # Does nothing?
GPIO.setup(COLUMNS[5], GPIO.IN, pull_up_down=GPIO.PUD_DOWN) # Column 7
GPIO.setup(COLUMNS[6], GPIO.IN, pull_up_down=GPIO.PUD_DOWN) # This is column 6
GPIO.setup(COLUMNS[7], GPIO.IN, pull_up_down=GPIO.PUD_DOWN) # Column 5
GPIO.setup(COLUMNS[8], GPIO.IN, pull_up_down=GPIO.PUD_DOWN) # DOWN high seems to be column 4
GPIO.setup(COLUMNS[9], GPIO.IN, pull_up_down=GPIO.PUD_DOWN) # DOWN high seems to be column 3
GPIO.setup(COLUMNS[10], GPIO.IN, pull_up_down=GPIO.PUD_DOWN) # DOWN high seems to be column 2
GPIO.setup(COLUMNS[11], GPIO.IN, pull_up_down=GPIO.PUD_UP) # DOWN high seems to be column?????

for row in ROWS:
    GPIO.setup(row, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

while True:
    output = ""
    for pin in COLUMNS + ROWS:
        output = output + ("%s" % GPIO.input(pin))
    print(output)

# while True:
#     output = ""
#     for column in COLUMNS:
#         GPIO.output(column, 1)

#         for row in ROWS:
#             output = output + ("%s" % GPIO.input(row))
#         GPIO.output(column, 0)
#     print(output)
