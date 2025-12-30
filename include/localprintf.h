#pragma once

#include <cstdarg>
#include <iobuf.h>

int localFputs(const char *, FILE * = stdin);

int localvfprintf(FILE *, const char *, va_list);
