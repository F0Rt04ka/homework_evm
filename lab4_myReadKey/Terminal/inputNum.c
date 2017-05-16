#include "terminal.h"

int inputNum(int* number)
{
    char inputString[5];
    int inputNumber;

    rk_mytermregime(1, 0, 0, 0, 0);
    scanf("%5s", inputString);

    rk_mytermregime(0, 1, 1, 1, 1);

    //TODO: сделать проверку корректности вводимых данных
    if (inputString[0] != '+') {
        sscanf(inputString, "%X", &inputNumber);
    } else {
        sscanf(inputString, "+%X", &inputNumber);
        setCommandFlag(&inputNumber, 1);
    }

    *number = inputNumber;

    return 0;
}