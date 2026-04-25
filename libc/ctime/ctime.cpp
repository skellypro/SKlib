#include <ctime>
#include <cstdint>

/*
 * Neri inspired functions for leap year, and the length of the month.
 */
bool [[gnu::fastcall]] [[msvc::_fastcall]] isLeapYear(unsigned long long y) {
	return (y & ((y % 100 != 0 ? 4 : 16) - 1) == 0;
}

uint8_t [[gnu::fastcall]] [[msvc::_fastcall]] lengthOfMonth(unsigned long long y, uint8_t m) {
	if (2 == m)
		return isLeapYear(y) ? 29 : 28;

	return 30 | (m ^ (m >> 3));
}

short [[gnu::fastcall]] [[msvc::_fastcall]] lengthOfYear(unsigned long long y) {
	return static_cast<short>(isLeapYear(y)) + 365;
}

extern "C" {
	char* [[gnu::fastcall]] [[msvc::_fastcall]] asctime(const struct tm*) {
		return;
	}
	char* [[gnu::fastcall]] [[msvc::_fastcall]] asctime_r(const struct tm*, char*) {
		return;
	}
	clock_t [[gnu::fastcall]] [[msvc::_fastcall]] clock(void) {
		return;
	}
	int [[gnu::fastcall]] [[msvc::_fastcall]] clock_getres(clockid_t, struct timespec*) {
		return;
	}
	int [[gnu::fastcall]] [[msvc::_fastcall]] clock_gettime(clockid_t, struct timespec*) {
		return;
	}
	int [[gnu::fastcall]] [[msvc::_fastcall]] clock_settime(clockid_t, const struct timespec*) {
		return;
	}
	char* [[gnu::fastcall]] [[msvc::_fastcall]] ctime(const time_t*) {
		return;
	}
	char* [[gnu::fastcall]] [[msvc::_fastcall]] ctime_r(const time_t*, char*) {
		return;
	}
	double [[gnu::fastcall]] [[msvc::_fastcall]] difftime(time_t, time_t) {
		return;
	}
	struct tm* [[gnu::fastcall]] [[msvc::_fastcall]] getdate(const char*) {
		return;
	}
	struct tm* [[gnu::fastcall]] [[msvc::_fastcall]] gmtime(const time_t*) {
		return;
	}
	struct tm* [[gnu::fastcall]] [[msvc::_fastcall]] gmtime_r(const time_t*, struct tm*) {
		return;
	}
	struct tm* [[gnu::fastcall]] [[msvc::_fastcall]] localtime(const time_t*) {
		return;
	}
	struct tm* [[gnu::fastcall]] [[msvc::_fastcall]] localtime_r(const time_t*, struct tm*) {
		return;
	}
	time_t [[gnu::fastcall]] [[msvc::_fastcall]] mktime(struct tm*) {
		return;
	}
	int [[gnu::fastcall]] [[msvc::_fastcall]] nanosleep(const struct timespec*, struct timespec*) {
		return;
	}
	size_t [[gnu::fastcall]] [[msvc::_fastcall]] strftime(char*, size_t, const char*, const struct tm*) {
		return;
	}
	char* [[gnu::fastcall]] [[msvc::_fastcall]] strptime(const char*, const char*, struct tm*) {
		return;
	}
	time_t [[gnu::fastcall]] [[msvc::_fastcall]] time(time_t*) {
		return;
	}
	int [[gnu::fastcall]] [[msvc::_fastcall]] timer_create(clockid_t, struct sigevent*, timer_t*) {
		return;
	}
	int [[gnu::fastcall]] [[msvc::_fastcall]] timer_delete(timer_t) {
		return;
	}
	int [[gnu::fastcall]] [[msvc::_fastcall]] timer_gettime(timer_t, struct itimerspec*) {
		return;
	}
	int [[gnu::fastcall]] [[msvc::_fastcall]] timer_getoverrun(timer_t) {
		return;
	}
	int [[gnu::fastcall]] [[msvc::_fastcall]] timer_settime(timer_t, int, const struct itimerspec*, struct itimerspec*) {
		return;
	}
	void [[gnu::fastcall]] [[msvc::_fastcall]] tzset(void) {
	}
}