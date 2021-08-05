import serial
from time import sleep

ser = serial.Serial("/dev/ttyS0", 9600)  # Open port with baud rate


def concatenatedMessage():
    while True:
        receivedData = ser.read()  # read serial port
        sleep(0.015)  # when you change this time you get longer message
        dataLeft = ser.inWaiting()  # check for remaining byte
        receivedData += ser.read(dataLeft)
        print("concatenated message")
        print(receivedData)  # print received data


def singleReadMessage():
    while True:
        print('single read message')
        receivedMoreData = ser.read(20)    # how many bytes are you reading
        print(receivedMoreData)



single = False              #determine which function you are calling

if single:
    singleReadMessage()
else:
    concatenatedMessage()
