/*
 * math.cpp
 *
 *  Created on: Nov 17, 2024
 *      Author: sean
 * Last Change: Nov 17, 2024
 */

#include <cmath>

using namespace std;

extern "C" {

	//Trigonometric functions
	float cos (float x) {
		return 0;
	}

	double cos (double x) {
		return x;
	}

	long double cos (long double x) {
		return 0;
	}

	float sin (float x) {
		return 0;
	}

	double sin (double x) {
		return 0;
	}

	long double sin (long double x) {
		return 0;
	}

	float tan (float x) {
		return 0;
	}

	double tan (double x) {
		return 0;
	}

	long double tan (long double x) {
		return 0;
	}

	//Powers and Exponents
	//!!!!!AVOID RECURSION TO PREVENT STACK OVERFLOWS!!!!!!
	float pow (float base, float exponent) {
		if(0.0 == exponent)
			return 1;
        bool negative = 0.0 > exponent;
        exponent = negative ? -exponent : exponent;
		float result = base;
		while(--exponent)
			result *= base;
        if(negative)
            result /= 1;
		return result;
	}

	double pow (double base, double exponent) {
		if(0.0 == exponent)
			return 1;
        bool negative = 0.0 > exponent;
        exponent = negative ? -exponent : exponent;
		double result = base;
		while(--exponent)
			result *= base;
        if(negative)
            result /= 1;
		return result;
	}

	long double pow (long double base, long double exponent) {
		if(0.0 == exponent)
			return 1;
        bool negative = 0.0 > exponent;
        exponent = negative ? -exponent : exponent;
		long double result = base;
		while(--exponent)
			result *= base;
        if(negative)
            result /= 1;
		return result;
	}

	//Other functions
	float fabs(float x) {
		return x < 0 ? -x : x;
	}

	double fabs(double x) {
		return x < 0 ? -x : x;
	}

	long double fabs(long double x) {
		return x < 0 ? -x : x;
	}

	float abs(float x) {
		return fabs(x);
	}

	double abs(double x) {
		return fabs(x);
	}

	long double abs(long double x) {
		return fabs(x);
	}

	float fma (float x, float y, float z) {
		return x * y + z;
	}

	double fma (double x, double y, double z) {
		return x * y + z;
	}

	long double fma (long double x, long double y, long double z) {
		return x * y + z;
	}
	/*
	template<class Type1, class Type2, class Type3>
	double fma (Type1 x      , Type2 y      , Type3 z) {
		return x * y + z;
	}
	*/

}
