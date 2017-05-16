#include "terminal.h"

void printTerminalMemory(void)
{
    int selector = getSelector();
    int number, command, operand;
    char string[5];

    // Выводим значение всех ячеек
    for (int i = 0; i < 100; ++i) {
        mt_gotoXY(2 + ((i % 10) * 6), (i / 10) + 2);
        sc_memoryGet(i, &number);
        sc_commandDecode(number, &command, &operand);
        sprintf(string, " %02X%02X", command & 0x7F, operand & 0x7F);
        if (isCommandFlag(number)) {
            string[0] = '+';
        }

        if (i == selector) {
            mt_setbgcolor(Red);
            myPrint(string);
            mt_setbgcolor(Default);
        } else {
            myPrint(string);
        }
    }

    // Получаем значение выбранной ячейки и рисуем его большими символами
    sc_memoryGet(selector, &number);
    sprintf(string, " %4X", number & 0x3FFF);
    myReplace(string);
    if (isCommandFlag(number)) {
        string[0] = '+';
    } else {
        string[0] = ' ';
    }
    printTerminalBigChars(string);
}