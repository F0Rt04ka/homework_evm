#include "terminal.h"

int inputMemoryCell(void)
{
    int inputNumber;

    setDefaultString();
    myPrint("Input: ");
    inputNum(&inputNumber);

    //TODO: сделать проверку корректности вводимых данных

    sc_memorySet(getSelector(), inputNumber);
    printTerminalMemory();

    return 0;
}