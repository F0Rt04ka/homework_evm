#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "../lab1_mySimpleComputer/mySimpleComputer.h"
#include "../lab3_myBigChars/myBigChars.h"
#include "../lab2_consoleSC/myTerms.h"
#include "myReadkey.h"
#include "Terminal/terminal.h"

int main()
{


    if (rk_mytermregime(0, 1, 1, 1, 1) != 0) {
        mt_setfgcolor(Red);
        myPrint("Ошибка установки режима терминала\n");
        mt_setfgcolor(Default);
        return -1;
    }

    sc_memoryInit();
    sc_regInit();

    if (printTerminalAllBox() != 0) {
        mt_setfgcolor(Red);
        myPrint("Увеличьте размер терминального окна!\n");
        mt_setfgcolor(Default);
        return -1;
    }

    enum keys key;
    do {
        rk_readkey(&key);
        keyHandler(key);
    } while (key != KEY_q);

    return 0;
}