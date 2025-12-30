
//#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include <cstring>

#include <localstring.h>
#include <localprintf.h>
#include <iobuf.h>

int localPrintString(FILE* buffer, const char* str) {
	int written = 0;

	while (str[written]) {
		fputc(str[written], buffer);
		written++;
	}

	return written-1;
}

int printBase(int base, FILE* buffer = stdout) {
	switch (base) {
	case 16:
		return localPrintString(buffer, "0x");
	case 8:
		fputc('0', buffer);
		return 1;
	case 2:
		return localPrintString(buffer, "0b");
	default:
		return 0;
	}
}
int getBase(char formatc){
	switch (formatc) {
	case 'b':
		return 2;
	case 'o':
		return 8;
	case 'x': case 'X':	case 'p':
		return 16;
	default:
		return 10;
	}
}

int localvfprintf(FILE* buffer, const char* format, va_list args) {
	// Simple implementation using fwrite
	int base, written = 0;
	char numBuffer[65];

	for (size_t i = 0; format[i]; i++) {
		switch (format[i]) {
		case '%':
			i++;
			switch (format[i]) {
				// TODO: what if there is a number between % and the format specifier?
			case 'd':
			case 'i':
				integerToString((int)va_arg(args, int), numBuffer);
				written += localPrintString(buffer, numBuffer);
				break;
			case 'b':
			case 'o':
			case 'u':
			case 'z':
			case 'x':
			case 'X':
			case 'p':
				base = getBase(format[i]);
				unsignedIntegerToString((unsigned int)va_arg(args, unsigned int), numBuffer, base);
				written += printBase(base, buffer);
				written += localPrintString(buffer, numBuffer);
				break;
			case 's':
				const char* strValue = (const char*)va_arg(args, const char*);
				written += localPrintString(buffer, strValue);
				break;
			case 'c':
				fputc((char)va_arg(args, int), buffer);
				written++;
				break;
			case 'f':
				floatToString((float)va_arg(args, float), numBuffer);
				written += localPrintString(buffer, numBuffer);
				break;
			case 'l':
				// TODO: handle %ld, %li, %lu, %lx, %lo, etc.
				switch (format[i + 1]) {
				case 'f':
					doubleToString((double)va_arg(args, double), numBuffer);
					written += localPrintString(buffer, numBuffer);
					i++;
					break;
				case 'd':
				case 'i':
					longIntegerToString((long)va_arg(args, long), numBuffer);
					written += localPrintString(buffer, numBuffer);
					i++;
					break;
				case 'b':
				case 'o':
				case 'u':
				case 'z':
				case 'p':
				case 'x':
				case 'X':
					base = getBase(format[i + 1]);
					unsignedLongIntegerToString((unsigned long)va_arg(args, unsigned long), numBuffer, base);
					written += printBase(base, buffer);
					written += localPrintString(buffer, numBuffer);
					i++;
					break;
				default:
					// Unsupported format specifier, just print it as is
					fputc('%', buffer);
					fputc('l', buffer);
					written += 2;
				}
				break;
			case '%':
				fputc('%', buffer);
				written++;
				break;
			default:
				// Unsupported format specifier, just print it as is
				fputc('%', buffer);
				fputc(format[i], buffer);
				written += 2;
				break;
			}
			break;
		case '\\':
			i++;
			// TODO: handle more escape sequences
			switch (format[i]) {
			case 'n':
				fputc('\n', buffer);
				written++;
				break;
			case 't':
				fputc('\t', buffer);
				written++;
				break;
			case '\\':
			default:
				fputc(format[i], buffer);
				written++;
				break;
			}
			break;
		default:
			fputc(format[i], buffer);
			written++;
		}
	}
	return written;
}