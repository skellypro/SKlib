
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

int localPuts(const char * str, FILE * buffer = stdin) {
	return localPrintString(buffer, str);
}

int localvfprintf(FILE* buffer, const char* format, va_list * args) {
	int base, written = 0;
	char numBuffer[65];

	for (size_t i = 0; format[i]; i++) {
		switch (format[i]) {
		case '%':
			i++;
			switch (format[i]) {
				// TODO: implement format flag specifiers
				// TODO: implement format width specifiers
				// TODO: precision is implemented in the ToString function, get it to work here
				// TODO: implement format length specifiers
			case 'd': case 'i':
				integerToString((int)va_arg(*args, int), numBuffer);
				written += localPrintString(buffer, numBuffer);
				break;
			case 'b': case 'o': case 'u': case 'z': case 'x': case 'X': case 'p':
				base = getBase(format[i]);
				unsignedIntegerToString((unsigned int)va_arg(*args, unsigned int), numBuffer, base);
				written += printBase(base, buffer);
				written += localPrintString(buffer, numBuffer);
				break;
			case 's':
				const char* strValue = (const char*)va_arg(*args, const char*);
				written += localPrintString(buffer, strValue);
				break;
			case 'c':
				//putc((char)va_arg(args, int), buffer);
				written += localPrintString(buffer, (char[]){((char)va_arg(*args, char)), 0});
				//written++;
				break;
			case 'f':
				floatToString((float)va_arg(*args, float), numBuffer);
				written += localPrintString(buffer, numBuffer);
				break;
			case 'l':
				// TODO: handle %ld, %li, %lu, %lx, %lo, etc.
				switch (format[i + 1]) {
				case 'f':
					doubleToString((double)va_arg(*args, double), numBuffer);
					written += localPrintString(buffer, numBuffer);
					i++;
					break;
				case 'd': case 'i':
					longIntegerToString((long)va_arg(*args, long), numBuffer);
					written += localPrintString(buffer, numBuffer);
					i++;
					break;
				case 'b': case 'o': case 'u': case 'z': case 'p': case 'x': case 'X':
					base = getBase(format[++i]);
					unsignedLongIntegerToString((unsigned long)va_arg(*args, unsigned long), numBuffer, base);
					written += printBase(base, buffer);
					written += localPrintString(buffer, numBuffer);
					break;
				default:
					// Unsupported format specifier, just print it as is
					written += localPrintString(buffer, "%l");
				}
				break;
			case '%':
				written += localPrintString(buffer, "%");
				break;
			default:
				// Unsupported format specifier, just print it as is
				written += localPrintString(buffer, (char[]){'%', format[i], 0});
				break;
			}
			break;
		case '\\':
			i++;
			// TODO: handle more escape sequences
			switch (format[i]) {
			case 'n':
				written += localPrintString(buffer, "\n");
				break;
			case 'r':
				written += localPrintString(buffer, "\r");
				break;
			case 'v':
				written += localPrintString(buffer, "\v");
				break;
			case 'b':
				written += localPrintString(buffer, "\b");
				break;
			case 'f':
				written += localPrintString(buffer, "\f");
				break;
			case 't':
				written += localPrintString(buffer, "\t");
				break;
			case '\\':
			default:
				written += localPrintString(buffer, (char[]){format[i], 0});
				break;
			}
			break;
		default:
			written += localPrintString(buffer, (char[]){format[i], 0});
		}
	}
	return written;
}