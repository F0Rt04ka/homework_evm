#include "terminal.h"

int instructionCounter = 0;

void printTerminalInstructionCounter(void)
{
    char buf[4];

    sprintf(buf, "%4d", instructionCounter);
    mt_gotoXY(68, 5);
    myPrint(buf);
}

int changeInstructionCounter(void)
{
    int inputNumber;
    myPrint("Input Instruction Counter: ");
    if (inputNum(&inputNumber) != 0) {
        myPrint("Not a number!");
        return -1;
    }

    if ((inputNumber >= 0) && (inputNumber < 0x100)) {
        instructionCounter = inputNumber;
    } else {
        myPrint("Accumutalor range: from 0 to 99 (0x63)");
        return -1;
    }
    setSelector(instructionCounter);

    return 0;
}

void setInstructionCounter(int number)
{
    instructionCounter = number;
    setSelector(instructionCounter);
}

int getInstructionCounter(void)
{
    return instructionCounter;
}