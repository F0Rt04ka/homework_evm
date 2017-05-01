#include "terminal.h"

int inputMemoryCell(void)
{
    char inputString[5];
    int inputNumber;

    setDefaultString();
    rk_mytermregime(1, 0, 0, 0, 0);

    myPrint("Input: ");
    scanf("%5s", inputString);

    rk_mytermregime(0, 1, 1, 1, 1);

//    // Проверка корректности вводимых данных (не работает. надоело дебажить) Сергей, сделай чтобы работало:)
//    for (int i = 0; i < 5; ++i) {
//        if ((inputString[0] == '+' && i == 0)) {
//            continue;
//        } else if (inputString[0] != '+' && i == 4) {
//            break;
//        } else if (inputString[i] == 0){
//            break;
//        }
//
//        if ((inputString[i] >= 97 || inputString[i] >= 65 || inputString[i] >= 48) &&
//            (inputString[i] <= 102 || inputString[i] <= 70 || inputString[i] <= 57)) {
//            error = 1;
//        }
//
//        if (error) {
//            rk_mytermregime(0, 0, 1, 0, 1);
//            return -1;
//        }
//    }

    if (inputString[0] != '+') {
        sscanf(inputString, "%X", &inputNumber);
    } else {
        sscanf(inputString, "+%X", &inputNumber);
    }

    sc_memorySet(getSelector(), inputNumber);
    printTerminalMemory();

    return 0;
}