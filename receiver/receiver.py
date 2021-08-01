import serial
from time import sleep

ser = serial.Serial ("/dev/ttyS0", 9600)    #Open port with baud rate

i=0

while True:
    received_data = ser.read()              #read serial port
    sleep(0.02)
    # print(ser.inWaiting())
    # data_left = ser.inWaiting()             #check for remaining byte
    # received_data += ser.read(data_left)
    print(received_data)                   #print received data
    i+=1
    print(i)
    # ser.write(received_data)                #transmit data serially