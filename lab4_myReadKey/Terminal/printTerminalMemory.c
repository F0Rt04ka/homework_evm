#include "terminal.h"

void printTerminalMemory(void)
{
    int selector = getSelector();
    int number;
    char string[5];

    // Выводим значение всех ячеек
    for (int i = 0; i < 100; ++i) {
        mt_gotoXY(2 + ((i % 10) * 6), (i / 10) + 2);
        sc_memoryGet(i, &number);
        sprintf(string, "+%4.X", number);

        for (int j = 1; j < 5; ++j) {
            if (string[j] == ' ')
                string[j] = '0';
        }

        if (i == selector) {
            mt_setbgcolor(Red);
            myPrint(string);
            mt_setbgcolor(Default);
            printTerminalBigChars(string);
        } else {
            myPrint(string);
        }
    }

    // Получаем занчение выбранной ячейки и рисуем его большими символами
    sc_memoryGet(selector, &number);
    sprintf(string, "+%4.X", number);
    printTerminalBigChars(string);

    setDefaultString();
}