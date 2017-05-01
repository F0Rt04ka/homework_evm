#include "terminal.h"

int printTerminalAllBox(void)
{
    int rows, cols;
    mt_getscreensize(&rows, &cols);
    if (rows < 26 || cols < 81) {
        return -1;
    }

    mt_clrscr();

    // Memory Box
    bc_box(1, 1, 61, 12);
    mt_gotoXY(25, 1);
    myPrint("Memory");

    // Accumulator Box
    bc_box(62, 1, 80, 3);
    mt_gotoXY(66, 1);
    myPrint("Accumulator");

    // instructionCounter Box
    bc_box(62, 4, 80, 6);
    mt_gotoXY(62, 4);
    myPrint("instructionCounter");

    // Operation Box
    bc_box(62, 7, 80, 9);
    mt_gotoXY(66, 7);
    myPrint("Operation");

    // Flags Box
    bc_box(62, 10, 80, 12);
    mt_gotoXY(68, 10);
    myPrint("Flags");

    // Bigchars Box
    bc_box(1, 13, 50, 24);

    // Info keys Box
    bc_box(51, 13, 80, 24);
    mt_gotoXY(63, 13);
    myPrint("Keys");

    mt_setfgcolor(Green);
    mt_gotoXY(52, 15);
    myPrint("l  - load");
    mt_gotoXY(52, 16);
    myPrint("s  - save");
    mt_gotoXY(52, 17);
    myPrint("r  - run");
    mt_gotoXY(52, 18);
    myPrint("t  - step");
    mt_gotoXY(52, 19);
    myPrint("i  - reset");
    mt_gotoXY(52, 20);
    myPrint("F5 - accumulator");
    mt_gotoXY(52, 21);
    myPrint("F6 - instructionCounter");
    mt_setfgcolor(Default);

    printTerminalMemory();
    printTerminalFlags();

    setDefaultString();

    return 0;
}