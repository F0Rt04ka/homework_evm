#include <stdio.h>

int main() {
    mt_clrscr();
    mt_gotoXY(10, 5);
    mt_setfgcolor(2);
    mt_setbgcolor(3);
    
    printf("Hello, World!\n");
    mt_setdefaultcolors();
    return 0;
}
