/*
 * string.h
 *
 *  Created on: Jan 20, 2023
 *      Author: sean
 */

#pragma once

#include "null.h"
#include "sizet.h"

extern "C" {
	size_t strlen(const char* str);

	int strcmp(const char* a, const char* b);

	char* strcat(char* destination, const char* source);

	const char* strchr(const char* str, int character);

	char* strchr(char* str, int character);
}