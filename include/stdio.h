#pragma once

#include <stdarg.h>
#include <stdlib.h>

#include <iobuf.h>

extern "C" {
    
    int fputs(const char *, FILE *);
    int puts(const char *);

    int printf(const char* format, ...);
    int fprintf(FILE* buffer, const char* format, ...);
    int sprintf(char* buffer, const char* format, ...);
    int snprintf(char* buffer, size_t sizeOfBuffer, const char* format, ...);
	int vprintf(const char* format, va_list args);
	int vsprintf(char* buffer, const char* format, va_list args);
    int vsnprintf(char * buffer, size_t sizeOfBuffer, const char * format, va_list args);
	int vfprintf(FILE* buffer, const char* format, va_list args);
}