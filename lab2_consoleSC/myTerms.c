#include <stdio.h>
#include <sys/ioctl.h>

#include "myTerms.h"

#define ESCAPE_CLEAR_SCREEN "\E[H\E[J"
#define ESCAPE_RESET_COLORS "\E[0m"
#define ESCAPE_CURSOR_VISIBLE "\E[?25h\E[?8c"
#define ESCAPE_CURSOR_INVISIBLE "\E[?25l\E[?1c"
#define ERROR -1

int mt_clrscr (void)
{
    printf("%s", ESCAPE_CLEAR_SCREEN);

    return 0;
}

int mt_gotoXY (int X, int Y)
{
    int rows, cols;

    if (!mt_getscreensize(&rows, &cols))
    if ((Y < rows) && (Y >= 0) && (X < cols) && (X >= 0)) {
        printf("\E[%d;%dH", Y, X);
        return 0;
    }

    return ERROR;
}

int mt_getscreensize (int *rows, int *cols)
{
    struct winsize winSize;

    if(!ioctl(0, TIOCGWINSZ, &winSize)) {
        *rows = winSize.ws_row;
        *cols = winSize.ws_col;

        return 0;
    }

    return ERROR;
}

int mt_setfgcolor (enum colors color)
{
    int textColor = 30 + (int)color;

    printf("\E[%dm", textColor);

    return 0;
}

int mt_setbgcolor (enum colors color)
{
    int bgColor = 40 + (int)color;

    printf("\E[%dm", bgColor);

    return 0;
}

int mt_setdefaultcolors (void)
{
    printf("%s", ESCAPE_RESET_COLORS);

    return 0;
}
