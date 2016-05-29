#!/usr/bin/python
# ardu2Pi.py
################
import serial
from Tkinter import *
import time
DEVICE = '/dev/ttyACM0'
BAUD = 9600
ser = serial.Serial(DEVICE, BAUD)
def one() :
  ser.write('1')
  print("I go forward")
  return
def two() :
  ser.write('2')
  print("I go backward")
  return
def three() :
  ser.write('3')
  print("I turn my self to the right")
  return
def four() :
  ser.write('4')
  print("And now in a the other direction")
  return
def five() :
  ser.write('5')
  print("Stop")
  return


time.sleep(1.5)
one()
time.sleep(1.5)
two()
time.sleep(1.5)
three()
time.sleep(4)
four()
time.sleep(4)
five()







