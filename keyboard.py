#!/usr/bin/env python3

import sys
import time

import RPi.GPIO as GPIO


COLUMNS = [25, 0, 1, 5, 6, 12, 13, 19, 21]
ROWS = [22, 23, 24, 10, 9, 11, 8, 7, 16, 26, 20]


state = [None, None, None, None, None, None, None, None, None, None, None]


def character(column, row):
    return [[None, "z",  "h",  "\t", "1",  "u",  "q",  "7",  None, None, None],
            [" ",  "x",  "j",  "a",  "2",  "i",  "w",  "8",  None, None, None],
            [None, "c",  "k",  "s",  "3",  "o",  "e",  "9",  None, None, None],
            [",",  "v",  "m",  "d",  "4",  "p",  "r",  "0",  None, None, None],
            [None, "b",  ".",  "f",  "5",  "l",  "t",  None, None, None, None],
            [None, "n",  None, "g",  "6",  "\n", "y",  "~",  None, None, None],
            [None, None, None, None, None, None, None, None, None, None, None],
            [None, None, None, None, None, None, None, None, None, None, None],
            [None, None, None, None, None, None, None, None, None, None, None]][column][row]


def event(character, down):
    if character is None:
        return
    if down:
        sys.stdout.write(character)
        sys.stdout.flush()


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
        row_index = None
        try:
            row_index = output.index(1)                
        except ValueError:
            pass
        if state[column_index] != row_index:
            if state[column_index] is not None:
                event(character(column_index, state[column_index]), False)
            if row_index is not None:
                event(character(column_index, row_index), True)
            state[column_index] = row_index
