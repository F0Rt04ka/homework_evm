#include "mySimpleComputer.h"

static size_t arraySize = 100;
static int* arrayPtr = NULL;
static int registr;


// Проверка правильности вводимого регистра
int checkReg (int reg)
{
    switch (reg) {
        case FLAG_A:
        case FLAG_B:
        case FLAG_C:
        case FLAG_D:
        case FLAG_E:
            return 1;

        default:
            return 0;
    }
}


int sc_memoryInit (void)
{
    arrayPtr = (int*)calloc(arraySize, sizeof(int));

    // Не удалось выделить память
    if (arrayPtr == NULL) {
        return -1;
    }

    return 0;
}


int sc_memorySet (int address, int value)
{
    // Память не инициализирована
    if (arrayPtr == NULL) {
        return -1;
    }

    if ((address < arraySize) && (address >= 0)) {

        arrayPtr[address] = value;

        return 0;
    }

    return -1;
}


int sc_memoryGet (int address, int* value)
{
    // Память не инициализирована
    if (arrayPtr == NULL) {
        return -1;
    }

    // Не верный адрес памяти
    if ((address > arraySize) && (address < 0)) {
        return -1;
    }

    *value = arrayPtr[address];

    return 0;
}


int sc_memorySave (char *filename)
{
    FILE* filePtr;
    if ((filePtr = fopen(filename, "wb")) == NULL) {
        return -1;
    }

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
    if (filePtr == NULL) {
        return -1;
    }

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
    if (!checkReg(reg)) {
        return -1;
    }

   if (value == 0) {
       registr = registr & ~(reg);
   } else if (value == 1) {
       registr = registr | (reg);
   } else
       return -1;

   return 0;
}


int sc_regGet (int reg, int* value)
{
    if (!checkReg(reg)) {
        return -1;
    }

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
            return -1;
        }
    } else {
        sc_regSet(FLAG_E, 1);
        return -1;
    }

    return 0;
}


int sc_commandDecode (int value, int* command, int* operand)
{
    *command = (value >> 7);
    *operand = value & (~(*command << 7));

    if (*command >= 10 && *command <= 76) {
        if (*operand >= 0 && *operand < 128) {
            return 0;
        } else {
            return -1;
        }
    } else {
        sc_regSet(FLAG_E, 1);

        return -1;
    }
}


int isCommandFlag (int address)
{
    int number;
    if (sc_memoryGet(address, &number) != -1) {
        int result = (number >> 14);
        if (result == 1 || result == 0) {
            return result;
        }
    }

    return -1;
}


int setCommandFlag (int address, int flag) {
    int number;
    if (sc_memoryGet(address, &number) != -1) {
        if (flag == 1) {
            sc_memorySet(address, number | 16384);
            return 0;
        } else if (flag == 0) {
            sc_memorySet(address, number & ~16384);
            return 0;
        }
    }

    return -1;
}