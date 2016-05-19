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
def one() :
  ser.write('1')
  return
def two() :
  ser.write('2')
  return
def three() :
  ser.write('3')
  return
root.title("Arduino im Test")
Label(text="ROBOTRON FORWARD BACKWARD CONTROLLER", fg="#0A116B").pack()
Label(text="ROBOT YOU LEFT YOUR PANTIES IN MY KITCHEN",fg="#0A116B").pack()
Button(text='forward', command=one, background="#00cd00", fg="#FFFFFF").pack()
Button(text='backward', command=two, background="#B03060", fg="#FFFFFF").pack()
Button(text='stop', command=three, background="#CD0000", fg="#FFFFFF").pack()
root.mainloop()
