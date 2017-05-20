#include "terminal.h"

int printTerminalFlags(void)
{
    int reg;
    int err = 0;

    if (sc_regGet(FLAG_OVERFLOW, &reg) != -1) {

        mt_gotoXY(65, 11);

        if (reg) {
            myPrint("V");
        } else {
            myPrint("_");
        }
    } else {
        err = -1;
    }

    if (sc_regGet(FLAG_DIVISION, &reg) != -1) {

        mt_gotoXY(68, 11);

        if (reg) {
            myPrint("0");
        } else {
            myPrint("_");
        }
    } else {
        err = -1;
    }

    if (sc_regGet(FLAG_MEMORY, &reg) != -1) {

        mt_gotoXY(71, 11);

        if (reg) {
            myPrint("M");
        } else {
            myPrint("_");
        }
    } else {
        err = -1;
    }

    if (sc_regGet(FLAG_INTERRUPT, &reg) != -1) {

        mt_gotoXY(74, 11);

        if (reg) {
            myPrint("T");
        } else {
            myPrint("_");
        }
    } else {
        err = -1;
    }

    if (sc_regGet(FLAG_COMMAND, &reg) != -1) {

        mt_gotoXY(77, 11);

        if (reg) {
            myPrint("C");
        } else {
            myPrint("_");
        }
    } else {
        err = -1;
    }

    return err;
}