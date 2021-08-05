#include <stdio.h>
#include <modbus.h>
#include <iostream>

using namespace std;


//COMMAND FOR COMPILING
//sudo g++ -std=c++11 -I /usr/include/modbus receiver.cpp -o receiver -lmodbus -lpthread

//BASED ON: https://stackoverflow.com/questions/29602698/create-a-simple-client-server-using-modbus-in-c

int main(void) {
    //Create a new RTU context
    modbus_t *ctx = modbus_new_rtu("/dev/ttyS0", 9600, 'N', 8, 1);

    if (!ctx) {
        fprintf(stderr, "Failed to create the context: %s\n", modbus_strerror(errno));
        exit(1);
    }

    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Unable to connect: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        exit(1);
    }

    //Set the Modbus address of the remote slave (to 3) it does not matter which- server takes from 0 to 7
    modbus_set_slave(ctx, 3);

    int startAddress = 0;
    int amountOfRegisters =5;

    // Store read registers values
    uint16_t registersMemory[amountOfRegisters];


    //Read previous registers values
    int num = modbus_read_registers(ctx, startAddress, amountOfRegisters, registersMemory);

    cout<<"previous registers:";
     for (int i=0; i<amountOfRegisters;i++) {
            cout << registersMemory[i] << ", ";
        }
     cout<<endl;

    // new values for registers
    uint16_t src[] = {0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9};
    // write values to registers
    modbus_write_registers(ctx, startAddress, amountOfRegisters, src);

    // read registers
    modbus_read_registers(ctx, startAddress, amountOfRegisters, registersMemory);

    cout<<"next registers:";
    for (int i=0; i<amountOfRegisters;i++) {
        cout << registersMemory[i] << ", ";
    }
    cout<<endl;

    modbus_close(ctx);
    modbus_free(ctx);
}