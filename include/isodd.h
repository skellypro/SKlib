#pragma once

#define isOdd(n) (n % 2)

// Macros to expand isOdd(n) without pointless bloat
#define is_odd(n) (isOdd(n))
#define isEven(n) (!isOdd(n))
#define is_even(n) (isEven(n))