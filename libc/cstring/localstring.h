#pragma once

int integerToString(int value, char* buffer, int base = 10);
int unsignedIntegerToString(unsigned int value, char* buffer, int base = 10);
int longIntegerToString(long value, char* buffer, int base = 10);
int unsignedLongIntegerToString(unsigned long value, char* buffer, int base = 10);
int floatToString(float value, char* buffer, int precision = 6);
int doubleToString(double value, char* buffer, int precision = 12);