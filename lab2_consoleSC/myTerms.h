#ifndef LAB2_MYTERMS_H
#define LAB2_MYTERMS_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <string.h>
#include <unistd.h>

enum colors {
    Black,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White,
    Default = 9
};

int mt_clrscr (void);

int mt_gotoXY (int X, int Y);

int mt_getscreensize (int *rows, int *cols);

int mt_setfgcolor (enum colors color);

int mt_setbgcolor (enum colors color);

#endif //LAB2_MYTERMS_H
