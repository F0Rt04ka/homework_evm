#include "signals.h"

void setSignals()
{
    signal(SIGALRM, timerHandler); // Сигнал таймера
    signal(SIGUSR1, userSignalHandler); // Пользовательский сигнал
}

void timerHandler(int sig)
{
    //CU();
    setInstructionCounter(getInstructionCounter() + 1);
    int value;
    sc_regGet(FLAG_INTERRUPT, &value);
    if (!value) {
        alarm(1);
    }
    printTerminalAccumulator();
    printTerminalOperation();
    printTerminalInstructionCounter();
    printTerminalFlags();
    printTerminalMemory();
}


void userSignalHandler(int sig)
{
    alarm(0);
    //sc_memoryInit();
    //write_used = 0;
    sc_regInit();
    sc_regSet(FLAG_INTERRUPT, 1);
    setInstructionCounter(0);
    setAccumulator(0);
}