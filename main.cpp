#include <stdio.h>
#include "applications.h"

int main(void)
{
    foo(1000);
    int x = 1000;
    int y = 109;
    int lenX = 12;
    int lenY = 1999;
    int err = doTocTou(&x, &lenX, &y, &lenY);

    return 0;
}