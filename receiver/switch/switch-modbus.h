#pragma once

#include "../modbus/modbus.h"
#include "../enums/memory-enum.h"
#include "../enums/error-enum.h"
#include <iostream>

#ifndef UART_MODBUS_SWITCH_H
#define UART_MODBUS_SWITCH_H


class SwitchModbus {
private:
    char *port;
    int baudrate;
    Modbus *modbus;

public:
    SwitchModbus(char *port = (char *) "/dev/ttyS0", int baudrate = 9600) {
        this->port = port;
        this->baudrate = baudrate;
        this->modbus = new Modbus(this->port, this->baudrate);
    };

    void switchModbusRequest(Memory memoryRegister, uint16_t writeValue = 0) {
        uint16_t response;
        switch (memoryRegister) {
            case MAIN_ERROR:
                response = this->modbus->readInputRegister(MAIN_ERROR);
                memoryMap[MAIN_ERROR] = response;
                break;
            case ERROR_VECTOR_1:
            case ERROR_VECTOR_2:
                uint16_t responseVector1;
                uint16_t responseVector2;
                responseVector1 = this->modbus->readInputRegister(ERROR_VECTOR_1);
                responseVector2 = this->modbus->readInputRegister(ERROR_VECTOR_2);

                memoryMap[ERROR_VECTOR_1] = responseVector1;
                memoryMap[ERROR_VECTOR_2] = responseVector2;

                int errorResponse;
                errorResponse = ((int) responseVector2 << 16) | responseVector1;

                errorVector.clear();


                for (const auto &errorIterator: errorMap) {

                    if (errorResponse & (1 << errorIterator.first)) {
                        errorVector.push_back(errorIterator.first);
                    }
                }

                break;

            case INPUT_REGISTER:
                this->modbus->writeInputRegister(INPUT_REGISTER, writeValue);

                // Reading register to check if it was set correctly. If this functionality is demanded  modbus_write_and_read_registers should be used
                response = this->modbus->readInputRegister(INPUT_REGISTER);
                memoryMap[INPUT_REGISTER] = response;

                break;
            case STATE_MACHINE_CODE:
                response = this->modbus->readInputRegister(STATE_MACHINE_CODE);
                memoryMap[STATE_MACHINE_CODE] = response;

                break;
            case FAN_VALUE:
                this->modbus->writeInputRegister(FAN_VALUE, writeValue);

                // Reading register to check if it was set correctly. If this functionality is demanded  modbus_write_and_read_registers should be used
                response = this->modbus->readInputRegister(FAN_VALUE);
                memoryMap[FAN_VALUE] = response;

                break;
            case FAN_SPEED:
                response = this->modbus->readInputRegister(FAN_SPEED);
                memoryMap[FAN_SPEED] = response;
                break;
            case VOLTAGE_BATTERY_1:
                response = this->modbus->readInputRegister(VOLTAGE_BATTERY_1);
                memoryMap[VOLTAGE_BATTERY_1] = response;
                break;
            case VOLTAGE_BATTERY_2:
                response = this->modbus->readInputRegister(VOLTAGE_BATTERY_2);
                memoryMap[VOLTAGE_BATTERY_2] = response;
                break;
            case VOLTAGE_BATTERY_3:
                response = this->modbus->readInputRegister(VOLTAGE_BATTERY_3);
                memoryMap[VOLTAGE_BATTERY_3] = response;
                break;
            case OUTER_THERMISTOR_1:
                response = this->modbus->readInputRegister(OUTER_THERMISTOR_1);
                memoryMap[OUTER_THERMISTOR_1] = response;
                break;
            case OUTER_THERMISTOR_2:
                response = this->modbus->readInputRegister(OUTER_THERMISTOR_2);
                memoryMap[OUTER_THERMISTOR_2] = response;
                break;
            case INNER_THERMISTOR_1:
                response = this->modbus->readInputRegister(INNER_THERMISTOR_1);
                memoryMap[INNER_THERMISTOR_1] = response;
                break;
            case INNER_THERMISTOR_2:
                response = this->modbus->readInputRegister(INNER_THERMISTOR_2);
                memoryMap[INNER_THERMISTOR_2] = response;
                break;
            case INNER_THERMISTOR_3:
                response = this->modbus->readInputRegister(INNER_THERMISTOR_3);
                memoryMap[INNER_THERMISTOR_3] = response;
                break;
            case VOLTAGE_LINE_5V:
                response = this->modbus->readInputRegister(VOLTAGE_LINE_5V);
                memoryMap[VOLTAGE_LINE_5V] = response;
                break;
            case VOLTAGE_LINE_12V:
                response = this->modbus->readInputRegister(VOLTAGE_LINE_12V);
                memoryMap[VOLTAGE_LINE_12V] = response;
                break;
            case CURRENT_LINE_12V:
                response = this->modbus->readInputRegister(CURRENT_LINE_12V);
                memoryMap[CURRENT_LINE_12V] = response;
                break;
        }
    }
};


#endif //UART_MODBUS_SWITCH_H
