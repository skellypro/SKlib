#pragma once

#include <stdarg.h>
#include <stdlib.h>

#include <iobuf.h>

extern "C" {
    int printf(const char* format, ...);
    int fprintf(FILE* buffer, const char* format, ...);
    int sprintf(char* buffer, const char* format, ...);
    int snprintf(char* buffer, size_t sizeOfBuffer, const char* format, ...);
}