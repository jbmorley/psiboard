#!/usr/bin/env python3

import time

import RPi.GPIO as GPIO


COLUMNS = [25, 0, 1, 5, 6, 12, 13, 19, 21]
ROWS = [22, 23, 24, 10, 9, 11, 8, 7, 16, 26, 20]

GPIO.setmode(GPIO.BCM)

for column in COLUMNS:
    print("Configuring BCM %d..." % column)
    GPIO.setup(column, GPIO.OUT)

for row in ROWS:
    print("Configuring BCM %d..." % row)
    GPIO.setup(row, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

while True:
    output = ""
    for column in COLUMNS:
        GPIO.output(column, 1)
        time.sleep(0.05)
        for row in ROWS:
            output = output + ("%s" % GPIO.input(row))
        GPIO.output(column, 0)
    print(output)
    exit()
