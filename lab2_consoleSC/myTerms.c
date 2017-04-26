#include "myTerms.h"

#define ESCAPE_CLEAR_SCREEN "\E[H\E[J"
#define ESCAPE_RESET_COLORS "\E[0m"
#define ESCAPE_CURSOR_VISIBLE "\E[?25h\E[?8c"
#define ESCAPE_CURSOR_INVISIBLE "\E[?25l\E[?1c"

// Считает количество цифр в числе
int countsOfDigits(int number)
{
    if (number == 0) {
        return 1;
    }

    int count = 0;
    while (number != 0) {
        count++;
        number /= 10;
    }

    return count;
}

int mt_clrscr (void)
{
    write(1, ESCAPE_CLEAR_SCREEN, strlen(ESCAPE_CLEAR_SCREEN));

    return 0;
}

int mt_gotoXY (int X, int Y)
{
    int rows = 0, cols = 0;

    if (!mt_getscreensize(&rows, &cols))
    if ((Y < rows) && (Y >= 0) && (X < cols) && (X >= 0)) {
        char* buf = (char*)malloc((7 + countsOfDigits(X) + countsOfDigits(Y)) * sizeof(char));
        sprintf(buf, "\E[%d;%dH", Y, X);
        write(1, buf, strlen(buf));
        free(buf);

        return 0;
    }

    return -1;
}

int mt_getscreensize (int *rows, int *cols)
{
    struct winsize winSize;

    if (!ioctl(0, TIOCGWINSZ, &winSize)) {
        *rows = winSize.ws_row;
        *cols = winSize.ws_col;

        return 0;
    }

    return -1;
}

int mt_setfgcolor (enum colors color)
{
    char buf[6];
    sprintf(buf, "\E[3%dm", (int)color);
    write(1, buf, strlen(buf));

    return 0;
}

int mt_setbgcolor (enum colors color)
{
    char buf[6];
    sprintf(buf, "\E[4%dm", (int)color);
    write(1, buf, strlen(buf));

    return 0;
}
