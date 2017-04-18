#include <stdio.h>
#include "myTerms.h" 

int main() {
    mt_clrscr();
    mt_gotoXY(10, 5);
    mt_setfgcolor(Red);
    mt_setbgcolor(White);
    
    printf("Hello, World!\n");
    mt_setfgcolor(Default);
    mt_setbgcolor(Default);
    return 0;
}
