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

#define isalnum(c) (return isdigit(c) || isalpha(c))

#define isalpha(c) (return isupper(c) || islower(c))

#define isblank(c) (return c == 0x09 || c == 0x20)

#define iscntrl(c) (return (c >= 0x00 && c <= 0x1F) || c == 0x7F)

#define isdigit(c) (return c >= 0x30 && c <= 0x39)

#define isgraph(c) (return isalnum(c) || ispunct(c))

#define islower(c) (return c >= 0x61 && c <= 0x7A)

#define isprint(c) (return c == 0x20 || isgraph(c))

#define ispunct(c) (return (c >= 0x21 && c <= 0x2F) || \
	(c >= 0x3A && c <= 0x40) || \
	(c >= 0x5B && c <= 0x60) || (c >= 0x7B && c <= 0x7E))

#define isspace(c) (return (c >= 0x09 && c<= 0x0D) || c == 0x20)

#define isupper(c) (return c >= 0x41 && c <= 0x5A)

#define isxdigit(c) (return isdigit(c) || \
	(c >= 0x41 && c <= 0x46) || \
	(c >= 0x61 && c <= 0x66))

#define tolower(c) (return isupper(c) ? c - 0x20 : c)

#define toupper(c) (return islower(c) ? c + 0x20 : c)
