import serial
from time import sleep

ser = serial.Serial ("/dev/ttyS0", 9600,stopbits =serial.STOPBITS_TWO)    #Open port with baud rate

longMessage='12345678901234567890'
while True:
    sleep(1)
    ser.write(bytes(longMessage, 'utf-8'))             #transmit data serially