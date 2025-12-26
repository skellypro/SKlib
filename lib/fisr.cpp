/*
 * fisr.cpp
 * @Author: Sean Kelly
 * Description: Quake III's fast inverse square root function,
 * 32 bit, 64 bit, and generic versions
 * 
 * Reference:
 * https://www.youtube.com/watch?v=p8u_k2LIZyo
 * 
 * This file is safe to include.
 */
#ifndef __FISR_CPP__
#define __FISR_CPP__

#include<cinttypes>

#define THREEHALFS 1.5F
#define WTF 0x5f3759df	// Named after the comment in the line that uses this number

template<class T = float>
T fastInverseSqrt(T n) {
	long long i = 0;
	T x, y;

	x = n * 0.5F;
	y = n;
	i = *(reinterpret_cast<long long*>(&y));	// Genius approach for loading a float to a GPR(aka the evil floating point bit hack)
	i = WTF - (i >> 1);							// shifting by 1 bit divides the number by 2
	y = *(reinterpret_cast<T*>(&i));
	y = y * (THREEHALFS - (x * y * y));			// Newton itteration
	
	return y;
}

template<class T = float>
T fastAccurateInverseSqrt(T n) {
	T y = fastInverseSqrt(n);
	y = y * (THREEHALFS - (x * y * y));			// Second Newton itteration for better approximation
	return y;
}

extern "C" {
    float fisr(float n) {
        return fastInverseSqrt((float)n);
    }

    double fisr(double n) {
        return fastInverseSqrt((float)n);
    }

	float faisr(float n){
		return fastAccurateInverseSqrt((float)n);
	}

	double faisr(double n) {
		return fastAccurateInverseSqrt((double)n);
	}
}

template<class T>
extern T fisr(const T &n) {
    return fastInverseSqrt(dynamic_cast<T>n);
}

template<class T>
extern T faisr(const T &n) {
	return fastAccurateInverseSqrt(dynamic_cast<T>n);
}

#endif