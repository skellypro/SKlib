#pragma once

#ifndef M_PI
#define M_PI	3.1415926535897932384
#endif

extern "C" {

	//Trigonometric functions
	float cos (float x);

	double cos (double x);

	long double cos (long double x);

	float sin (float x);

	double sin (double x);

	long double sin (long double x);

	float tan (float x);

	double tan (double x);

	long double tan (long double x);

	//Powers and Exponents
	//!!!!!AVOID RECURSION TO PREVENT STACK OVERFLOWS!!!!!!
	float pow (float base, float exponent);

	double pow (double base, double exponent);

	long double pow (long double base, long double exponent);

	//Other functions
	float fabs(float x);
	double fabs(double x);
	long double fabs(long double x);
	float abs(float x);
	double abs(double x);
	long double abs(long double x);
	float fma (float x, float y, float z);
	double fma (double x, double y, double z);
	long double fma (long double x, long double y, long double z);
}
