/*
 * longfastints.h
 *
 *  Created on: Jun 24, 2025
 *      Author: sean
 * Last Change:	Jun 24, 2025
 *
 * Description:	Describe longfastints.h here
 */

#ifndef INCLUDE_LONGFASTINTS_H_
#define INCLUDE_LONGFASTINTS_H_

union alignas(16) uint128_split_t___ {
	unsigned : 128;
	struct {
		unsigned : 64, : 64;
	};
	struct {
		unsigned : 32, : 32, : 32, :32;
	};
	struct {
		unsigned : 16, : 16, : 16, : 16, : 16, : 16, : 16, : 16;
	};
	struct {
		unsigned : 8, : 8, : 8, : 8, : 8, : 8, : 8, : 8, : 8, : 8, : 8, : 8, : 8, : 8, : 8, : 8;
	};
};

#endif /* INCLUDE_LONGFASTINTS_H_ */
