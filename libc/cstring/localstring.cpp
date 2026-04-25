
#include <cstring>

#include "localstring.h"

// yeah, pointless memory usage, but if it's faster this way, is it pointless?
const static char DIGITS[] = "0123456789ABCDEF";

// TODO: make these functions part of a utility library
int integerToString(int value, char* buffer, int base = 10) {
	return static_cast<int>(longIntegerToString(value, buffer, base));
}
int unsignedIntegerToString(unsigned int value, char* buffer, int base = 10) {
	return unsignedLongIntegerToString(value, buffer, base);
}
int longIntegerToString(long value, char* buffer, int base = 10) {
	char temp[65];
	int i = 0;
	bool isNegative = false;
	if (value < 0 && base == 10) {
		isNegative = true;
		value = -value;
	}
	if (value == 0) {
		buffer[0] = '0';
		buffer[1] = '\0';
		return 2;
	}
	while (value != 0) {
		int rem = value % base;
		temp[i++] = DIGITS[rem];
		value /= base;
	}
	if (isNegative) {
		temp[i++] = '-';
	}
	int j = 0;
	while (i > 0) {
		buffer[j++] = temp[--i];
	}
	buffer[j] = '\0';
	return j;
}
int unsignedLongIntegerToString(unsigned long value, char* buffer, int base = 10) {
	char temp[65];
	int i = 0;
	if (value == 0) {
		buffer[0] = '0';
		buffer[1] = '\0';
		return 2;
	}
	while (value != 0) {
		int rem = value % base;
		temp[i++] = DIGITS[rem];
		value /= base;
	}
	int j = 0;
	while (i > 0) {
		buffer[j++] = temp[--i];
	}
	buffer[j] = '\0';
	return j;
}
int floatToString(float value, char* buffer, int precision = 6) {
	return static_cast<float>(doubleToString(value, buffer, precision));
}
int doubleToString(double value, char* buffer, int precision = 6) {
	int intPart = (int)value;
	double fracPart = value - (double)intPart;
	int len = integerToString(intPart, buffer, 10);
	buffer += len;
	*buffer++ = '.';
	for (int i = 0; i < precision; i++) {
		fracPart *= 10.0;
		int digit = (int)fracPart;
		*buffer++ = DIGITS[digit];
		fracPart -= (double)digit;
	}
	*buffer = '\0';
	return len + 1 + precision; // total length
}