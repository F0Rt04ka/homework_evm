#include "terminal.h"

int printTerminalFlags(void)
{
    int reg;
    int err = 0;

    if (sc_regGet(FLAG_A, &reg) != -1) {

        mt_gotoXY(65, 11);

        if (reg) {
            myPrint("A");
        } else {
            myPrint("_");
        }
    } else {
        err = -1;
    }

    if (sc_regGet(FLAG_B, &reg) != -1) {

        mt_gotoXY(68, 11);

        if (reg) {
            myPrint("B");
        } else {
            myPrint("_");
        }
    } else {
        err = -1;
    }

    if (sc_regGet(FLAG_C, &reg) != -1) {

        mt_gotoXY(71, 11);

        if (reg) {
            myPrint("C");
        } else {
            myPrint("_");
        }
    } else {
        err = -1;
    }

    if (sc_regGet(FLAG_D, &reg) != -1) {

        mt_gotoXY(74, 11);

        if (reg) {
            myPrint("D");
        } else {
            myPrint("_");
        }
    } else {
        err = -1;
    }

    if (sc_regGet(FLAG_E, &reg) != -1) {

        mt_gotoXY(77, 11);

        if (reg) {
            myPrint("E");
        } else {
            myPrint("_");
        }
    } else {
        err = -1;
    }

    return err;
}