#include <cstdlib>

#include <iobuf.h>


extern "C" FILE _iob[FOPEN_MAX] = {
	{ 0, (char *) 0, (char *) 0, _READ, 0, 0, 0, (char *) 0},				// stdin
	{ 0, (char *) 0, (char *) 0, _WRITE, 1, 0, 0, (char *) 0},				// stdout
	{ 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 , 0, 0, (char *) 0}		// stderr
};

// TODO: _fillbuf and _flushbuf are needed for any of this to work
int _fillbuf(FILE * buffer) {
	return EOF;
}

int _flushbuf(int, FILE * buffer) {
	return EOF;
}