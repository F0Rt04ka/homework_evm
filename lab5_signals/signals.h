#include <signal.h>
#include <fcntl.h>

#include "../lab1_mySimpleComputer/mySimpleComputer.h"
#include "../lab3_myBigChars/myBigChars.h"
#include "../lab2_consoleSC/myTerms.h"
#include "../lab4_myReadKey/myReadkey.h"
#include "../lab4_myReadKey/Terminal/terminal.h"

void setSignals();

void timerHandler(int sig);
void userSignalHandler(int sig);

