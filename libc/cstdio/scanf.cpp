/*
 * scanf.cpp
 *
 *  Created on: Apr 24, 2024
 *      Author: sean
 */

#include<stdarg.h>
#include<stdio.h>

extern "C" {
    int scanf(const char * format, ...) {
        return 0;
    }

    int fscanf(FILE * buffer, const char * format, ...) {
        return 0;
    }
}