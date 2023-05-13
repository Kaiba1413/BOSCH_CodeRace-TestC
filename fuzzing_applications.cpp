#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int DoSomethingInterestingWithMyAPI(const uint8_t *pInData, int DataLen)
{
    if (DataLen > 2000)
    {
        return 1;
    }

    for (int i = 0; i < DataLen; i++)
        printf("%d\n", pInData[i]);
    return 0;
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  DoSomethingInterestingWithMyAPI(data, size);
  return 0;  // Values other than 0 and -1 are reserved for future use.
}