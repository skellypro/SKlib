/*
 * string.cpp
 *
 *  Created on: Oct 28, 2023
 *      Author: sean
 */

#include<stddef.h>
#include<stdint.h>
#include<string.h>

extern "C" {

	size_t strlen(const char* str)
	{
		size_t len = 0;
		while (str[len])
			len++;
		return len + 1;
	}

	int strcmp(const char* a, const char* b) {
        int result;
		if (a == b)
            result = 0;
        else
            for(size_t i = 0; a[i] && b[i]; i++)
                if(0 != (result = a[i] - b[i]))
                    break;
		return result;
	}

	char* strcat(char* destination, const char* source) {
		int i = strlen(destination), d = 0;
		do
			destination[i++] = source[d++];
		while(source[d]);
        /*
		for (destination[i] : c)
			i++;
        */
		return destination;
	}

    
    const char* strchr(const char* str, int character) {
        return strchr(str, character);
    }

    char* strchr(char* str, int character) {
        size_t i = 0;
        while (str[i] && (str[i] != character))
            i++;
        return &str[i];
    }

}
