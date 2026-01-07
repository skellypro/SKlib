/*
 * printf.cpp
 *
 *  Created on: Apr 24, 2024
 *      Author: sean
 */

#include <stdarg.h>
#include <string.h>

#include <localprintf.h>
#include <iobuf.h>

extern "C"{
	int fputs(const char * str, FILE * stream) {
		return localFputs(str, stream);
	}

	int puts(const char * str) {
		return localFputs(str);
	}

	int printf(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		int ret = localvfprintf(stdout, format, &args);
		va_end(args);
		return ret;
	}
	
	int fprintf(FILE* buffer, const char* format, ...) {
		va_list args;
		va_start(args, format);
		int ret = localvfprintf(buffer, format, &args);
		va_end(args);
		return ret;
	}

	int sprintf(char* buffer, const char* format, ...) {
		va_list args;
		va_start(args, format);
		int ret = vsprintf(buffer, format, args);
		va_end(args);
		return ret;
	}

	// TODO: implement vsnprintf and localvsnprintf
	int snprintf(char* buffer, size_t sizeOfBuffer, const char* format, ...) {
		va_list args;
		va_start(args, format);
		int ret = vsnprintf(buffer, sizeOfBuffer, format, args);
		va_end(args);
		return ret;
	}

	int vprintf(const char* format, va_list & args) {
		return localvfprintf(stdout, format, &args);
	}

	int vsprintf(char* buffer, const char* format, va_list & args) {
		FILE temp;
		temp._base = buffer;
        temp._ptr = buffer;
        temp._bufsiz = strlen(buffer);
        temp._flag = _READ;
		int ret = localvfprintf(&temp, format, &args);
		return ret;
	}

	// STUB::TODO: Fill this in
    int vsnprintf(char * buffer, size_t sizeOfBuffer, const char * format, va_list & args) {
        return 0;
    }

	int vfprintf(FILE* buffer, const char* format, va_list & args) {
		return localvfprintf(buffer, format, &args);
	}
}