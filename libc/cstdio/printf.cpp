/*
 * printf.cpp
 *
 *  Created on: Apr 24, 2024
 *      Author: sean
 */

#include<stdarg.h>
#include<stdio.h>

extern "C"{
    int printf(const char * format, ...) {
        return 0;
    }

    int fprintf(FILE * buffer, const char * format, ...) {
        return 0;
    }
}