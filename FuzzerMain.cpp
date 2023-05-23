/*
 * FuzzerMain.cpp
 *
 *  Created on: May 23, 2023
 *      Author: gogoCow
 */

#include <stdint.h>
#include <stddef.h>


extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    // Use data and size to test target program
    // ...
    
    return 0;
}