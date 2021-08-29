#include <stdio.h>
#include <modbus.h>
#include <iostream>


int main(void) {
    modbus_t *ctx;
    std::cout << "start1"<<std::endl;


    ctx = modbus_new_rtu("/dev/ttyS0", 115200, 'N', 8, 1);
    if (ctx == NULL) {
        fprintf(stderr, "Unable to create the libmodbus context\n");
        return -1;
    }

    modbus_set_slave(ctx, 1);

    if (modbus_connect(ctx) == -1) {
        std::cout << "Connection failed"<<std::endl;
//        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return -1;
    } else{
      std::cout << "Connected"<<std::endl;
    }
}


//sudo g++ -std=c++11 -I /usr/include/modb
//us test.cpp -o myTest1 -lmodbus -lpthread
