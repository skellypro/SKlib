/*
 * fisr.h
 * @Author: Sean Kelly
 * Description: Quake III's fast inverse square root function,
 * 32 bit, 64 bit, and generic versions
 * 
 * Reference:
 * https://www.youtube.com/watch?v=p8u_k2LIZyo
 */

#pragma once

/*
 * fisr()
 * arguments:
 *	- Real - the base number
 * 
 * Return type:
 *	- Real - the inverse square root of the base
 * 
 * Description:
 *	This fast invers square root function is derived from
 * Quake III's algorithm, with expansions for 64 bit numbers,
 * and a generic version.
 */
 extern "C"{
    float _fastcall fisr(float);

    double _fastcall fisr(double);
}