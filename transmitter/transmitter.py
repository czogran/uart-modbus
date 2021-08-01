import serial
from time import sleep

ser = serial.Serial ("/dev/ttyS0", 9600,stopbits =serial.STOPBITS_TWO)    #Open port with baud rate
print((9).to_bytes(2,byteorder='big'))
print(ser.stopbits)

ser.write(b'1')
# a=bytes(9)
# print(a.decode())
# print(bytearray(9))
# while True:
#     sleep(1)
#     # ser.write(b'hellossssssssssssssssssssssssssssss')                 #transmit data serially
#     ser.write(b'111')                 #transmit data serially