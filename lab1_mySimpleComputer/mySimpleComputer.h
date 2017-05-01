#ifndef HOMEWORKS_EVM_MYSIMPLECOMPUTER_H
#define HOMEWORKS_EVM_MYSIMPLECOMPUTER_H

    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>

    // Флаги регистра
    #define FLAG_A 0x1
    #define FLAG_B 0x2
    #define FLAG_C 0x4
    #define FLAG_D 0x8
    #define FLAG_E 0x10

    int sc_memoryInit (void);

    int sc_memorySet (int address, int value);

    int sc_memoryGet (int address, int *value);

    int sc_memorySave (char *filename);

    int sc_memoryLoad (char *filename);

    int sc_regInit (void);

    int sc_regSet (int reg, int value);

    int sc_regGet (int reg, int* value);

    int sc_commandEncode (int command, int operand, int* value);

    int sc_commandDecode (int value, int* command, int* operand);

    // Проверить присутс
    int checkCommandFlag (int address);

    int setCommandFlag (int address);

#endif //HOMEWORKS_EVM_MYSIMPLECOMPUTER_H
