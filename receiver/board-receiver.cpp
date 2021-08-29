#pragma once

#include <iostream>
#include <vector>
#include "enums/error-enum.h"
#include "enums/memory-enum.h"
#include "modbus/modbus.h"
#include "switch/switch-modbus.h"

using namespace std;

//COMMAND FOR COMPILING
//sudo g++ -std=c++11 -I /usr/include/modbus receiver.cpp -o receiver -lmodbus -lpthread
//sudo g++ -std=c++11 -I /usr/include/modbus board-receiver.cpp -o receiver -lmodbus -lpthread

int main() {
    cout << "Welcome in board receiver program :D" << endl;
    Modbus modbusObject;

    SwitchModbus switchModbus;
    switchModbus.switchModbusRequest(MAIN_ERROR);
    switchModbus.switchModbusRequest(INPUT_REGISTER);
    switchModbus.switchModbusRequest(ERROR_VECTOR_1);
    switchModbus.switchModbusRequest(ERROR_VECTOR_2);
    switchModbus.switchModbusRequest(INPUT_REGISTER, 2);


    return 0;
}
