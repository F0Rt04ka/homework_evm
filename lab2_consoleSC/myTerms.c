#include <stdio.h>
#include <sys/ioctl.h>

#include "myTerms.h"

#define ESCAPE_CLEAR_SCREEN "\E[H\E[J"
#define ESCAPE_CURSOR_POSITION(string, column) "\E["(string)##";"##(column)##"H"
#define ESCAPE_SET_COLORS(text, bg) "\E["##text##";"###bg##"m"
#define ESCAPE_RESET_COLORS "\E[0m"
#define ESCAPE_CURSOR_VISIBLE "\E[?25h\E[?8c"
#define ESCAPE_CURSOR_INVISIBLE "\E[?25l\E[?1c"

static int textColor = 37;
static int bgColor = 40;

int mt_clrscr (void)
{
    printf("%s", ESCAPE_CLEAR_SCREEN);

    return 0;
}

int mt_gotoXY (int X, int Y)
{
    char *result = ESCAPE_CURSOR_POSITION(X, Y);
    printf("%s", result);

    return 0;
}

int mt_getscreensize (int *rows, int *cols)
{
    struct winsize winSize;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &winSize);

    *rows = winSize.ws_row;
    *cols = winSize.ws_col;

    return 0;
}

int mt_setfgcolor (enum colors color)
{
    textColor = 30 + color;
    printf("%s", ESCAPE_SET_COLORS(textColor, bgColor));

    return 0;
}

int mt_setbgcolor (enum colors color)
{
    bgColor = 40 + color;
    printf("%s", ESCAPE_SET_COLORS(textColor, bgColor));

    return 0;
}