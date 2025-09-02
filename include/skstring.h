/*
 * skstring.h
 *
 *  Created on: Jan 20, 2023
 *      Author: sean
 */

#ifndef INCLUDE_SKSTRING_H_
#define INCLUDE_SKSTRING_H_



namespace sk {

	typedef unsigned long int size_t;

	static inline size_t strlen(const char * str)
	{
		size_t len = 0;
		while (str[len])
			len++;
		return len;
	}

	static inline bool strcmp(const char * a, const char * b){
		if(a != b){
			int i = 0;
			do{
				if(a[i] != b[i])
					return false;
				i++;
			}while(a[i] & b[i]);
		}
		return true;
	}
}

#endif /* INCLUDE_SKSTRING_H_ */
