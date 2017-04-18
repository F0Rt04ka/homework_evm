#include "myBigChars.h"

int bc_printA(char* str)
{
    int bufLength = 4 + strlen(str);
    char* buf;
    buf = (char*)malloc(bufLength);
    sprintf(buf, "\E(0%s", str);
    write(1, buf, strlen(buf));
    free(buf);

    buf = (char*)malloc(4);
    sprintf(buf, "\E(B");
    write(1, buf, strlen(buf));
    
    return 0;
}
