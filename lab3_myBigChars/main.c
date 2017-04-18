#include<stdio.h>
#include <string.h>

#include "myBigChars.h"
#include "../lab2_consoleSC/myTerms.h"

#define MEM "Memory"

int main()
{
    int i;
    char buf[6];

    mt_clrscr();

    bc_box(1, 1, 61, 12);
    mt_gotoXY(25, 1);
    strcpy(buf, MEM);
    write(1, buf, 6);
//
//    bc_box(62, 1, 80, 3);
//    mt_gotoXY(66, 1);
//    printf("Accumulator");
//
//    bc_box(62, 4, 80, 6);
//    mt_gotoXY(62, 4);
//    printf("instructionCounter");
//
//    bc_box(62, 7, 80, 9);
//    mt_gotoXY(66, 7);
//    printf("Operation");
//
//    bc_box(62, 10, 80, 12);
//    mt_gotoXY(68, 10);
//    printf("Flags");
//
//    bc_box(1, 13, 50, 24);
//
//    bc_box(51, 13, 80, 24);
//    mt_gotoXY(53, 13);
//    printf("Keys");
//
//    mt_gotoXY(52, 14);
//    printf("l  - load");
//    mt_gotoXY(52, 15);
//    printf("s  - save");
//    mt_gotoXY(52, 16);
//    printf("r  - run");
//    mt_gotoXY(52, 17);
//    printf("t  - step");
//    mt_gotoXY(52, 18);
//    printf("i  - reset");
//    mt_gotoXY(52, 19);
//    printf("F5 - accumulator");
//    mt_gotoXY(52, 20);
//    printf("F6 - instructionCounter");
//
//    for (i = 0; i < 100; ++i) {
//        mt_gotoXY(2 + ((i % 10) * 6), (i / 10) + 2);
//        printf("+0000");
//    }
//
//    int bigPlus[2] = BIG_PLUS;
//    bc_printbigchar(bigPlus, 2, 14, Black, Default);
//    int big9[2] = BIG_9;
//    bc_printbigchar(big9, 11, 14, Default, Default);
//    bc_printbigchar(big9, 20, 14, Default, Default);
//    bc_printbigchar(big9, 29, 14, Default, Default);
//    bc_printbigchar(big9, 38, 14, Default, Default);
//
//    mt_gotoXY(20, 4);
//    mt_setbgcolor(Red);
//    mt_setfgcolor(White);
//    printf("+9999");
//
//    mt_setbgcolor(Default);
//    mt_setfgcolor(Default);
    mt_gotoXY(1, 25);

    return 0;
}
