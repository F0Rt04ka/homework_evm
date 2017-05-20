#include "terminal.h"

int moveSelector(enum keys key)
{
    int selector = getSelector();
    int update = 0;

    if (key == KEY_up) {
        if (selector >= 10) {
            selector -= 10;
            update++;
        }
    } else if (key == KEY_down) {
        if (selector < 90) {
            selector += 10;
            update++;
        }
    } else if (key == KEY_left) {
        if (selector % 10 != 0) {
            selector--;
            update++;
        }
    } else if (key == KEY_right) {
        if (selector % 10 != 9) {
            selector++;
            update++;
        }
    } else {
        return -1;
    }

    // Проверяем произошло ли обновление
    if (update) {
        setSelector(selector);
        setInstructionCounter(getSelector());
        printTerminalInstructionCounter();
        printTerminalMemory();
        setDefaultString();

    }

    return 0;
}
