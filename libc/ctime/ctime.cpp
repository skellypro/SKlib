#include <ctime>

extern {
	char* asctime(const struct tm*) {
		return;
	}
	char* asctime_r(const struct tm*, char*) {
		return;
	}
	clock_t    clock(void) {
		return;
	}
	int        clock_getres(clockid_t, struct timespec*) {
		return;
	}
	int        clock_gettime(clockid_t, struct timespec*) {
		return;
	}
	int        clock_settime(clockid_t, const struct timespec*) {
		return;
	}
	char* ctime(const time_t*) {
		return;
	}
	char* ctime_r(const time_t*, char*) {
		return;
	}
	double     difftime(time_t, time_t) {
		return;
	}
	struct tm* getdate(const char*) {
		return;
	}
	struct tm* gmtime(const time_t*) {
		return;
	}
	struct tm* gmtime_r(const time_t*, struct tm*) {
		return;
	}
	struct tm* localtime(const time_t*) {
		return;
	}
	struct tm* localtime_r(const time_t*, struct tm*) {
		return;
	}
	time_t     mktime(struct tm*) {
		return;
	}
	int        nanosleep(const struct timespec*, struct timespec*) {
		return;
	}
	size_t     strftime(char*, size_t, const char*, const struct tm*) {
		return;
	}
	char* strptime(const char*, const char*, struct tm*) {
		return;
	}
	time_t     time(time_t*) {
		return;
	}
	int        timer_create(clockid_t, struct sigevent*, timer_t*) {
		return;
	}
	int        timer_delete(timer_t) {
		return;
	}
	int        timer_gettime(timer_t, struct itimerspec*) {
		return;
	}
	int        timer_getoverrun(timer_t) {
		return;
	}
	int        timer_settime(timer_t, int, const struct itimerspec*, struct itimerspec*) {
		return;
	}
	void       tzset(void) {}
}