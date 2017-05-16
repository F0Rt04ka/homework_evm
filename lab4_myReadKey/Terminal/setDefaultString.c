#include "terminal.h"

void setDefaultString(void)
{
    mt_setfgcolor(Default);
    mt_setbgcolor(Default);
    mt_gotoXY(1, 25);
    myPrint("                                                                ");
    mt_gotoXY(1, 25);
}