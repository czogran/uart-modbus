#pragma once

#include <modbus.h>
#include <string>
#include <iostream>
#include "../enums/memory-enum.h"


#ifndef UART_MODBUS_MODBUS_H
#define UART_MODBUS_MODBUS_H

using namespace std;

class Modbus {
private:
    char *port;
    int baudrate;
    modbus_t *modbusContext;

    void connect() {
        this->modbusContext = modbus_new_rtu(this->port, this->baudrate, 'N', 8, 1);

        if (modbus_connect(this->modbusContext) == -1) {
            fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
            modbus_free(this->modbusContext);
            return;
        }

        //Set the Modbus address of the remote slave (to 3) it does not matter which- server takes from 0 to 7
        modbus_set_slave(this->modbusContext, 3);
    };


public:
    Modbus(char *port = (char *) "/dev/ttyS0", int baudrate = 9600) {
        this->port = port;
        this->baudrate = baudrate;
        this->connect();
    };

    ~Modbus() {
        modbus_close(this->modbusContext);
        modbus_free(this->modbusContext);
    }

    void writeInputRegister(Memory registerNumber, uint16_t writeValue) {
        int rc = modbus_write_register(this->modbusContext, registerNumber, writeValue);
        if (rc == -1) {
            fprintf(stderr, "%s\n", modbus_strerror(errno));
            //            return -1;
        }
    }

    uint16_t readInputRegister(int registerNumber) {
        uint16_t registerMemory[1];
        int rc = modbus_read_registers(this->modbusContext, registerNumber, 1, registerMemory);

        if (rc == -1) {
            fprintf(stderr, "%s\n", modbus_strerror(errno));
//            return -1;
        }
        return registerMemory[0];
    }
};


#endif //UART_MODBUS_MODBUS_H
