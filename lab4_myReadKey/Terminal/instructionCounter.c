#include "terminal.h"

int instructionCounter = 0;

void printTerminalInstructionCounter(void)
{
    char buf[5];

    sprintf(buf, "+%04X", instructionCounter);
    mt_gotoXY(67, 5);
    myPrint(buf);
}

int changeInstructionCounter(void)
{
    int inputNumber;
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

    return 0;
}

void setInstructionCounter(int number)
{
    instructionCounter = number;
}

int getInstructionCounter(void)
{
    return instructionCounter;
}