#ifndef HOMEWORKS_EVM_MYSIMPLECOMPUTER_H
#define HOMEWORKS_EVM_MYSIMPLECOMPUTER_H

    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>

    // Флаги регистра
    #define FLAG_OVERFLOW 0x1
    #define FLAG_DIVISION 0x2
    #define FLAG_MEMORY 0x4
    #define FLAG_INTERRUPT 0x8
    #define FLAG_COMMAND 0x10

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

    // Проверить присутствие флага команды в числе
    int isCommandFlag (int number);

    // Установить или убрать флаг команды
    int setCommandFlag (int* number, int flag);

#endif //HOMEWORKS_EVM_MYSIMPLECOMPUTER_H
