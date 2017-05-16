#include "terminal.h"

int instructionCounter = 0;

void printTerminalInstructionCounter(void)
{
    char string[5];

    sprintf(string, "+%4X", instructionCounter);
    myReplace(string);
    mt_gotoXY(67, 5);
    myPrint(string);
}

void setInstructionCounter(int number)
{
    instructionCounter = number;
}

int getInstructionCounter(void)
{
    return instructionCounter;
}