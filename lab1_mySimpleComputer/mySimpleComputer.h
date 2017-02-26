#ifndef HOMEWORKS_EVM_MYSIMPLECOMPUTER_H
#define HOMEWORKS_EVM_MYSIMPLECOMPUTER_H

    // Including constants for register flags
    #include "constantsRegisterFlags.h"

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

    int getRegistr(void);

#endif //HOMEWORKS_EVM_MYSIMPLECOMPUTER_H
