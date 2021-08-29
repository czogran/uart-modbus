#!/usr/bin/env python
from pymodbus.version import version
from pymodbus.server.sync import StartSerialServer

from pymodbus.device import ModbusDeviceIdentification
from pymodbus.datastore import ModbusSequentialDataBlock, ModbusSparseDataBlock
from pymodbus.datastore import ModbusSlaveContext, ModbusServerContext

from pymodbus.transaction import ModbusRtuFramer, ModbusBinaryFramer



"""
BASED ON https://pymodbus.readthedocs.io/en/latest/source/example/synchronous_server.html
"""

def run_server():
    # you could also make a map with different ids
    store = ModbusSlaveContext(
        di=ModbusSequentialDataBlock(0, range(1,50)),
        co=ModbusSequentialDataBlock(0, range(50,100)),
        hr=ModbusSequentialDataBlock(0, range(100,150)),
        ir=ModbusSequentialDataBlock(0, range(150,200)))

    context = ModbusServerContext(slaves=store, single=True)

    # RTU:
    StartSerialServer(context, framer=ModbusRtuFramer,
                      port='/dev/ttyS0', timeout=.05, baudrate=9600)

if __name__ == "__main__":
    run_server()
