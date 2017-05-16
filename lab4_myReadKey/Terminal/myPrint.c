#include "terminal.h"

void myPrint(char* string)
{
    write(1, string, strlen(string));
}

void myReplace(char* string)
{
    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == ' ') {
            string[i] = '0';
        }
    }
}