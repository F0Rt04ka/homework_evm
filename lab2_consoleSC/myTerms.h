#ifndef LAB2_CONSOLE_MYTERMS_H
#define LAB2_CONSOLE_MYTERMS_H

enum colors{
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

int mt_clrscr (void);

int mt_gotoXY (int X, int Y);

int mt_getscreensize (int *rows, int *cols);

int mt_setfgcolor (enum colors color);

int mt_setbgcolor (enum colors color);

#endif //LAB2_CONSOLE_MYTERMS_H