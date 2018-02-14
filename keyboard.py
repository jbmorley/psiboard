#!/usr/bin/env python3

import sys
import time

import RPi.GPIO as GPIO


COLUMNS = [25, 0, 1, 5, 6, 12, 13, 19, 21]
ROWS = [22, 23, 24, 10, 9, 11, 8, 7, 16, 26, 20]


def character(column, row):
    return [[None, "z", "h", "\t", "1", "u", "q", "7", None, None, None],
            [" ",  "x", "j", "a",  "2", "i", "w", "8", None, None, None],
            [None, "c", "k", "s",  "3", "o", "e", "9"]][column][row]


GPIO.setmode(GPIO.BCM)

for column in COLUMNS:
    print("Configuring BCM %d..." % column)
    GPIO.setup(column, GPIO.OUT)

for row in ROWS:
    print("Configuring BCM %d..." % row)
    GPIO.setup(row, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

while True:
    for column_index, column in enumerate(COLUMNS):
        output = []
        GPIO.output(column, 1)
        time.sleep(0.01)
        for row in ROWS:
            output.append(GPIO.input(row))
        GPIO.output(column, 0)
        try:
            row_index = output.index(1)
            try:
                sys.stdout.write(character(column_index, row_index))
            except IndexError:
                sys.stdout.write("!")
            sys.stdout.flush()
        except (ValueError, IndexError):
            pass
