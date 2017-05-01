#include "terminal.h"

void myPrint(char* string)
{
    write(1, string, strlen(string));
}