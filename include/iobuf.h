#pragma once

#define FOPEN_MAX 20
#define OPEN_MAX FOPEN_MAX
#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2
#define _IOREAD 0x0001
#define _IOWRT 0x0002
#define _IORW 0x0004
#define _IOUNBUF 0x0008
#define _IORB 0x0040
#define _IOWB 0x0080
#define _IOAPPEND 0x0100
#define _IORWB 0x0200
#define _IOEOF 0x0010
#define _IOERR 0x0020
#define EOF (-1)
#define BUFSIZ 1024

typedef struct _iobuf {
	int _cnt;			// number of characters left
	char* _ptr;			// next character position
	char* _base;		// buffer base pointer
	int _flag;			// file status flags
	int _file;			// file descriptor
	int _charbuf;		// character buffer
	int _bufsiz;		// buffer size
	char* _tmpfname;	// temporary file name
}FILE;

enum _flags {
	_READ = _IOREAD, /* file open for reading */
	_WRITE = _IOWRT, /* file open for writing */
	_UNBUF = _IOUNBUF, /* file is unbuffered */
	_EOF = EOF, /* EOF has occurred on this file */
	_ERR = _IOERR /* error occurred on this file */
};

extern "C" FILE _iob[FOPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p) ((p)->flag & _EOF) != 0)
#define ferror(p) ((p)->flag & _ERR) != 0)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->_cnt >= 0 \
? (unsigned char) *(p)->_ptr++ : _fillbuf(p))

#define putc(x,p) (--(p)->_cnt >= 0 \
? *(p)->_ptr++ = (x) : _flushbuf((x),p))

#define getchar() getc(stdin)
#define putcher(x) putc((x), stdout)