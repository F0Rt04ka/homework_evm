#include "terminal.h"

int keyHandler(enum keys key)
{
    switch (key) {
        case KEY_l:
            // TODO: сделать запрос имени файла для загрузки
            if (!sc_memoryLoad(SAVE_MEMORY_FILE) && !rk_mytermrestore()) {
                printTerminalAllBox();
                myPrint("Load successful");
            } else {
                myPrint("Load error");
            }
            break;

        case KEY_s:
            // TODO: сделать запрос имени файла для сохранения
            if (!sc_memorySave(SAVE_MEMORY_FILE) && !rk_mytermsave()) {
                myPrint("Save successful");
            } else {
                myPrint("Save error");
            }
            break;

        case KEY_up:
        case KEY_down:
        case KEY_right:
        case KEY_left:
            moveSelector(key);
            break;

        case KEY_r:
            //TODO: run
            printf("r\n");
            break;

        case KEY_t:
            //TODO: step
            printf("t\n");
            break;

        case KEY_i:
            //TODO: reset
            printf("i\n");
            break;

        case KEY_q:
            myPrint("Exit\n");
            break;

        case KEY_f5:
            changeAccumulator();
            printTerminalAccumulator();
            setDefaultString();
            break;

        case KEY_f6:
            //TODO: instructionCounter
            printf("F6\n");
            break;

        case KEY_enter:
            if (inputMemoryCell() != 0) {
                setDefaultString();
                myPrint("Input error!");
            }
            break;

        case KEY_other:
            return -1;
    }

    return 0;
}