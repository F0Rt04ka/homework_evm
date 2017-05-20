#include "terminal.h"

int keyHandler(enum keys key)
{
    int value;
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
            sc_regGet(FLAG_INTERRUPT, &value);
            if (value) {
                sc_regSet(FLAG_INTERRUPT, 0);
                timerHandler(SIGALRM);
            } else {
                alarm(0);
                sc_regSet(FLAG_INTERRUPT, 1);
                setSelector(getInstructionCounter());
            }
            printTerminalFlags();
            break;

        case KEY_t:
            timerHandler(SIGALRM);
            setSelector(getInstructionCounter());
            printTerminalInstructionCounter();
            printTerminalFlags();
            printTerminalMemory();
            setDefaultString();
            break;

        case KEY_i:
            raise(SIGUSR1);
            setInstructionCounter(0);
            printTerminalAllBox();
            myPrint("Reset");
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
            changeInstructionCounter();
            printTerminalInstructionCounter();
            setDefaultString();
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
    setDefaultString();
    return 0;
}