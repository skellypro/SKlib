#pragma once

#include <cstdarg>
#include <iobuf.h>

int localvfprintf(FILE* buffer, const char* format, va_list args);
