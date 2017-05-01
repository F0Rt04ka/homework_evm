#include "terminal.h"

void printTerminalBigChars(char* string)
{
    if (strlen(string) != 5) {
        printf("ERROR!");
        return;
    }

    int big[2];

    // Рисуем символ знака отдельно
    getBigChar(string[0], big);
    bc_printbigchar(big, 2, 15, Cyan, Default);

    // Рисуем большую строку
    for (int i = 1; i < 5; ++i) {
        getBigChar(string[i], big);
        bc_printbigchar(big, 12 + ((i - 1) * 9), 15, Default, Default);
    }
}