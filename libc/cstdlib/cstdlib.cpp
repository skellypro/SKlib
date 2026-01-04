/*
 * stdlib.cpp
 *
 *  Created on: Nov 18, 2024
 *      Author: sean
 * Last Change:	Apr 28, 2025
 */

#include<cstdlib>
#include<cstdint>
#include<cstddef>
#include<cctype>
#include<cstring>
#include<cmath>
#include<cfloat>
#include<ctime>

using namespace std;

namespace skstdlib {
	static long long int skstrtoll(const char* str, char** endptr, int base);

	static union {
		long double nextRandNum = time(NULL) * .5;
		long long int randNum;
	};

	static long long int skrand(void);
	static void sksrand(unsigned long int seed);

	static void roll();
}
using namespace skstdlib;

extern "C" {

	//Integer math
	int abs(int n) {
		return n < 0 ? -n : n;
	}

	long int abs(long int n) {
		return labs(n);
	}

	long long int abs(long long int n) {
		return llabs(n);
	}

	long int labs (long int n) {
		return n < 0 ? -n : n;
	}

	long long int llabs (long long int n) {
		return n < 0 ? -n : n;
	}

	div_t div(int numer, int denom) {
		return {(numer / denom), (numer % denom)};
	}

	ldiv_t div(long int numer, long int denom) {
		return {(numer / denom), (numer % denom)};
	}

	lldiv_t div(long long int numer, long long int denom) {
		return {(numer / denom), (numer % denom)};
	}

	ldiv_t ldiv(long int numer, long int denom) {
		return {(numer / denom), (numer % denom)};
	}
	
	lldiv_t lldiv(long long int numer, long long int denom) {
		return {(numer / denom), (numer % denom)};
	}

	int rand (void) {
		return skrand();
	}

	void srand(unsigned long int seed) {
		return sksrand(seed);
	}

	//string conversion
	int atoi(const char *str) {
		return (int)skstrtoll(str, NULL, 10);
	}

	long int atol(const char *str) {
		return (long int)skstrtoll(str, NULL, 10);
	}

	long long int atoll(const char *str) {
		return skstrtoll(str, NULL, 10);
	}

	long int strtol(const char *str, char **endptr, int base) {
		return (long int)skstrtoll(str, endptr, base);
	}

	long long int strtoll(const char* str, char **endptr, int base) {
		return skstrtoll(str, endptr, base);
	}
}

namespace skstdlib {
	static long long int skstrtoll(const char* str, char** endptr, int base) {
		long double n = 0;
		size_t i = 0, sign = 0;

		for (size_t stringlength = strlen(str);
			i < stringlength && (isspace(str[i]) && !isxdigit(str[i]));
			i++);

		if (str[i] == '-') {
			sign++;
            i++;
		}

		if (!base) {
			for (size_t top = i + 2; i < top; i++) {
				switch (str[i]) {
				case '-':
					sign++;
					break;
				case '0':
					switch (str[i + 1]) {
					case 'd':
					case 'D':
					case '8':
					case '9':
						base = 10;
						break;
					case 'b':
					case 'B':
						base = 2;
						break;
					case 'x':
					case 'X':
						base = 16;
						break;
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
						base = 8;
						break;
					default:
						break;
					}
					break;
				default:
					break;
				}
			}
			if (!base)
				return 0;
		}

		while (isxdigit(str[i])) {
			long double number = isalpha(str[i]) ? toupper(str[i]) - 0x37 : str[i] - 0x30;
			if (number >= base && number < 0)
				goto skstrtollEND;
			n = (base * n) + number;
			i++;
		}

	skstrtollEND:
		if (endptr)
			*endptr = (char*)str + i;

		if (sign && n)
			n = sign > 1 ? 0 : -n;

		return (long long int)n;
	}

	static void roll() {
		clock_t c = clock();
		nextRandNum = (randNum * 1103515245 + 12345) * (c * CLOCKS_PER_SEC);
		randNum %= RAND_MAX;
	}

	static long long int skrand(void) {
		roll();
		return (unsigned int)randNum;
	}

	static void sksrand(unsigned long int seed) {
		randNum = seed;
		roll();
	}
}
