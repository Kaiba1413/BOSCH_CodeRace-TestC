#include <stdio.h>
#include "applications.h"

void foo(int x)
{
    int buf[10];
    buf[x] = 0;
    if (x == 1000)
    {
        printf("This is a simple vulnerability\n");
    }
}

int doTocTou(int *pInData, int *pInDataLen, int *pOutData, int *pOutDataLen)
{
    if ((*pInDataLen > 2000) || (*pOutDataLen > 2000))
    {
        return 1;
    }

    for (int i = 0; i < *pInDataLen; i++)
        printf("%d\n", pInData[i]);

    for (int i = 0; i < *pOutDataLen; i++)
        printf("%d\n", pOutData[i]);
}


