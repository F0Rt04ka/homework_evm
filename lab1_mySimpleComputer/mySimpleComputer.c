#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// Including constants for register flags
#include "constantsRegisterFlags.h"

#define true 1;
#define false 0;
#define ERROR -1;

static size_t arraySize = 100;
static int* arrayPtr = NULL;
static int registr;
static int flags[] = {FLAG_A, FLAG_B, FLAG_C, FLAG_D, FLAG_E};
static int countFlags = sizeof(flags) / sizeof(flags[1]);

_Bool checkReg (int reg)
{
    _Bool checkReg = false;
    int i;
    for (i = 0; i < countFlags; ++i) {
        if (reg == flags[i]) {
            checkReg = true;
            break;
        }
    }

    return checkReg;
}

int getRegistr(void)
{
    return registr;
}

int sc_memoryInit(void)
{
    arrayPtr = (int*) calloc(arraySize, sizeof(int));

    if (arrayPtr == NULL) return ERROR; // Не удалось выделить память

    return 0;
}

int sc_memorySet (int address, int value)
{
    if (arrayPtr == NULL) return ERROR;

    if ((address < arraySize) && (address >= 0)) {

        arrayPtr[address] = value;

        return 0;
    }

    return ERROR;
}

int sc_memoryGet (int address, int *value)
{
    if (arrayPtr != NULL)
        if ((address < arraySize) && (address >= 0)) {

            *value = arrayPtr[address];

            return 0;
        }

    return 1; // Ошибка
}

int sc_memorySave (char *filename)
{
    FILE* filePtr;
    if ((filePtr = fopen(filename, "wb")) == NULL) return ERROR;

    fwrite(arrayPtr, sizeof(int), arraySize, filePtr);
    fclose(filePtr);

    return 0;
}

int sc_memoryLoad (char *filename)
{
    // Check memory on empty
    if (arrayPtr == NULL) {
        sc_memoryInit();
    }

    FILE* filePtr;
    filePtr = fopen(filename, "rb");

    if (filePtr == NULL)
        return ERROR;

    fread(arrayPtr, sizeof(int), arraySize, filePtr);
    fclose(filePtr);

    return 0;
}

int sc_regInit (void)
{
    registr = 0;
    return 0;
}

int sc_regSet (int reg, int value)
{
    if (!checkReg(reg))
        return ERROR;

   if (value == 0) {
       registr = registr & ~(reg);
   } else if (value == 1) {
       registr = registr | (reg);
   } else
       return ERROR;

   return 0;
}

int sc_regGet (int reg, int* value)
{
    if (!checkReg(reg))
        return ERROR;

    if ((registr & reg) == 0) {
        *value = 0;
    } else if ((registr & reg) == reg) {
        *value = 1;
    }

    return 0;
}

int sc_commandEncode (int command, int operand, int* value)
{
    if (command >= 10 && command <= 76) {
        if (operand >= 0 && operand < 128) {
                *value = (command << 7) | operand;
            } else {
                return ERROR;
            }
        } else {
            sc_regSet(FLAG_E, 1);
            return ERROR;
        }
    return 0;
}


int sc_commandDecode (int value, int* command, int* operand)
{
    *command = (value >> 7);
    *operand = value & (~(*command << 7));

    if (*command >= 10 && *command <= 76) {
        if (*operand >= 0 && *operand < 128)
            return 0;
        else
            return ERROR;
    } else {
        sc_regSet(FLAG_E, 1);
        return ERROR;
    }
}

