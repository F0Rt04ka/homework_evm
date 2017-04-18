#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "myBigChars.h"
#include "../lab2_consoleSC/myTerms.h"

void myPrint(char* string);

int main()
{
    int i;
    char* buf;

    mt_clrscr();

    bc_box(1, 1, 61, 12);
    mt_gotoXY(25, 1);
    myPrint("Memory");

    bc_box(62, 1, 80, 3);
    mt_gotoXY(66, 1);
    myPrint("Accumulator");

    bc_box(62, 4, 80, 6);
    mt_gotoXY(62, 4);
    myPrint("instructionCounter");

    bc_box(62, 7, 80, 9);
    mt_gotoXY(66, 7);
    myPrint("Operation");

    bc_box(62, 10, 80, 12);
    mt_gotoXY(68, 10);
    myPrint("Flags");

    bc_box(1, 13, 50, 24);

    bc_box(51, 13, 80, 24);
    mt_gotoXY(53, 13);
    myPrint("Keys");

    mt_gotoXY(52, 14);
    myPrint("l  - load");
    mt_gotoXY(52, 15);
    myPrint("s  - save");
    mt_gotoXY(52, 16);
    myPrint("r  - run");
    mt_gotoXY(52, 17);
    myPrint("t  - step");
    mt_gotoXY(52, 18);
    myPrint("i  - reset");
    mt_gotoXY(52, 19);
    myPrint("F5 - accumulator");
    mt_gotoXY(52, 20);
    myPrint("F6 - instructionCounter");

    for (i = 0; i < 100; ++i) {
        mt_gotoXY(2 + ((i % 10) * 6), (i / 10) + 2);
        myPrint("+0000");
    }

    int bigPlus[2] = BIG_PLUS;
    bc_printbigchar(bigPlus, 2, 14, Black, Default);
    int big9[2] = BIG_9;
    bc_printbigchar(big9, 11, 14, Default, Default);
    bc_printbigchar(big9, 20, 14, Default, Default);
    bc_printbigchar(big9, 29, 14, Default, Default);
    bc_printbigchar(big9, 38, 14, Default, Default);

    mt_gotoXY(20, 4);
    mt_setbgcolor(Red);
    mt_setfgcolor(White);
    myPrint("+9999");

    mt_setbgcolor(Default);
    mt_setfgcolor(Default);
    mt_gotoXY(1, 25);

    return 0;
}

void myPrint(char* string)
{
    write(1, string, strlen(string));
}
