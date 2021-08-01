#include <stdio.h>
#include <modbus.h>
#include <iostream>


int main(void) {
    modbus_t *ctx;
    std::cout << "aaaa"<<std::endl;
    std::cout << "aaaa"<<std::endl;
    std::cout << "aaaa"<<std::endl;
    std::cout << "aaaa"<<std::endl;

    ctx = modbus_new_rtu("/dev/ttyS0", 115200, 'N', 8, 1);
    if (ctx == NULL) {
        fprintf(stderr, "Unable to create the libmodbus context\n");
        return -1;
    }

    modbus_set_slave(ctx, 1);

    if (modbus_connect(ctx) == -1) {
//        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return -1;
    }
}