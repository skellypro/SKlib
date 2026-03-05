#pragma once

#include <cstdarg>
#include <iobuf.h>

namespace sk {
	namespace skprintf {
		int [[gnu::fastcall]] [[msvc::__fastcall]] localFputs(const char*, FILE* = stdin);

		int [[gnu::fastcall]] [[msvc::__fastcall]] localvfprintf(FILE*, const char*, va_list*);
	}
}
