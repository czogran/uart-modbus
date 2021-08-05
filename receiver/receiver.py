#!/usr/bin/env python
from pymodbus.client.sync import ModbusSerialClient as ModbusClient
UNIT = 0x1

"""
BASED ON: https://pymodbus.readthedocs.io/en/latest/source/example/synchronous_client.html
"""

global client

def createClient():
    global client
    client = ModbusClient(method='rtu', port='/dev/ttyS0', timeout=1,
                          baudrate=9600)
    client.connect()


def clientWriteRegisterExample():
    print("clientWriteRegisterExample")
    previous = client.read_holding_registers(1, 1, unit=UNIT)
    print('previous: '+ str(previous.registers))

    rq = client.write_register(1, 8, unit=UNIT)
    updated = client.read_holding_registers(1, 1, unit=UNIT)
    print('updated: '+ str(updated.registers))


def clientWriteRegistersExample():
    print("clientWriteRegistersExample")
    previous = client.read_holding_registers(1, 10, unit=UNIT)
    print('previous: ' + str(previous.registers))

    rq = client.write_registers(1, [0] * 10, unit=UNIT)
    updated = client.read_holding_registers(1, 10, unit=UNIT)
    print('updated: '+ str(updated.registers))


if __name__ == "__main__":
    print("start example")
    createClient()
    clientWriteRegisterExample()
    clientWriteRegistersExample()
    client.close()