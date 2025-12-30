/*
 * ctype.h
 *
 *  Created on: Nov 17, 2024
 *      Author: sean
 * Last Change: Dec 30, 2025
 * Description:	My implementation of ctype.h.
 *
 */

#pragma once

#define isalnum(c) (isdigit(c) || isalpha(c))

#define isalpha(c) (isupper(c) || islower(c))

#define isblank(c) (0x09 == c || 0x20 == c)

#define iscntrl(c) ((0x00 <= c && 0x1F >= c) || 0x7F == c)

#define isdigit(c) (0x30 <= c && 0x39 >= c)

#define isgraph(c) (isalnum(c) || ispunct(c))

#define islower(c) (0x61 <= c && 0x7A >= c)

#define isprint(c) (0x20 == c || isgraph(c))

#define ispunct(c) (( 0x21 <= c && 0x2F >= c) || \
	(0x3A <= c && 0x40 >= c) || \
	(0x5B <= c && 0x60 >= c) || \
	(0x7B <= c && 0x7E >= c))

#define isspace(c) ((0x09 <= c && 0x0D >= c) || 0x20 == c)

#define isupper(c) (0x41 <= c && 0x5A <= c)

#define isxdigit(c) (isdigit(c) || \
	(0x41 <= c && 0x46 >= c) || \
	(0x61 <= c && 0x66 >=  c))

#define tolower(c) (isupper(c) ? c - 0x20 : c)

#define toupper(c) (islower(c) ? c + 0x20 : c)
