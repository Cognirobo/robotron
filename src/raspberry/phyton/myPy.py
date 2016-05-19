#!/usr/bin/python
# ardu2Pi.py
################
#  Port Detection
import serial
for com in range(0,4):
  try:
    PORT = '/dev/ttyACM'+str(com)
    BAUD = 9600
    board = serial.Serial(PORT,BAUD)
    board.close()
    break
  except:
    pass
########
# Blinks
from Tkinter import *
import time
DEVICE = '/dev/ttyACM'+str(com)
BAUD = 9600
ser = serial.Serial(DEVICE, BAUD)
root = Tk()
def five() :
  ser.write('5')
  return
def two() :
  ser.write('2')
  return
def seven() :
  ser.write('7')
  return
root.title("Arduino im Test")
Label(text="Raspberry Pi Geek 05/2013", fg="#0A116B").pack()
Label(text="RasPi gruesst Arduino!",fg="#0A116B").pack()
Button(text='2x blinken', command=two, background="#33D63B", fg="#FFFFFF").pack()
Button(text='5x blinken', command=five, background="#1DE4F2", fg="#FFFFFF").pack()
Button(text='7x blinken', command=seven, background="#DC0F16", fg="#FFFFFF").pack()
root.mainloop()
