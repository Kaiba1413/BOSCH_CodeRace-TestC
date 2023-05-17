#ifndef APPLICATIONS_H
#define APPLICATIONS_H

#include <stdint.h>

void foo(int x);
int doTocTou(int *pInData, int *pInDataLen, int *pOutData, int *pOutDataLen);
int DoSomethingInterestingWithMyAPI(const uint8_t *pInData, int DataLen);

#endif
