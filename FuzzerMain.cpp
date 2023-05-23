/*
 * FuzzerMain.cpp
 *
 *  Created on: May 23, 2023
 *      Author: gogoCow
 */

#include <stdint.h>
#include <stddef.h>
#include ".pipelines/main.h"
#include ".pipelines/resetRegister.h"
#include ".pipelines/registerMonitor.h"

int test_someTp (void)
{
   // someTp();
    return 1;
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    // Use data and size to test target program
    // ...
    test_someTp();
    return 0;
}