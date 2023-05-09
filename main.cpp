#include <stdio.h>

void foo(int x)
{
    int buf[10];
    buf[x] = 0;
    if (x == 1000)
    {
        printf("This is a simple vulnerability\n");
    }
}