#include "terminal.h"

static int selector = 0;

int getSelector(void)
{
    return selector;
}

void setSelector(int select)
{
    selector = select;
}