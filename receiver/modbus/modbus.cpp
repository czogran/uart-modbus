//
// Created by pawel on 22.08.2021.
//

#include "modbus.h"


//Modbus::Modbus(string port = "/dev/ttyS0", int baudrate = 9600) {
//    this->port = port;
//    this->baudrate = baudrate;
////    Modbus::
////    this->connect();
//}

//void Modbus::connect() {
//    //Create a new RTU context
//    modbus_t *ctx = modbus_new_rtu(Modbus::port, Modbus::baudrate, 'N', 8, 1);
//
//    if (!ctx) {
//        fprintf(stderr, "Failed to create the context: %s\n", modbus_strerror(errno));
//        exit(1);
//    }
//    std::cout << "connect"
//}

//Modbus::Modbus() {
//    this->port = "/dev/ttyS0";
//    this->baudrate = 9600;
//    std::cout << "start";
////    this->connect();
//}