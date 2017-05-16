#include "terminal.h"

void printTerminalOperation (void)
{
    int number, command, operand;

    sc_memoryGet(getSelector(), &number);
    sc_commandDecode(number, &command, &operand);

    char buf[8];
    mt_gotoXY(66, 8);
    sprintf(buf, " %02X : %02X", command & 0x7F, operand & 0x7F);
    if (isCommandFlag(number)) {
        buf[0] = '+';
    }
    myPrint(buf);
}