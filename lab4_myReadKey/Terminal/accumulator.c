#include "terminal.h"

int accumulator = 0;

int changeAccumulator()
{
    int inputNumber;

    setDefaultString();
    myPrint("Input accumulator: ");
    if (inputNum(&inputNumber) != 0) {
        myPrint("Not a number!");
        return -1;
    }

    if ((inputNumber >= 0) && (inputNumber < 0x8000)) {
        accumulator = inputNumber;
    } else {
        myPrint("Accumutalor is 15 bit wide");
        return -1;
    }

    printTerminalAccumulator();

    return 0;
}

int getAccumulator(void)
{
    return accumulator;
}

void printTerminalAccumulator(void)
{
    mt_gotoXY(67, 2);
    char buf[5];
    sprintf(buf, " %04X", accumulator & 0x3FFF);
    if (isCommandFlag(accumulator)) {
        buf[0] = '+';
    }
    myPrint(buf);;
}