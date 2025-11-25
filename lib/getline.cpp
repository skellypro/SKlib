/*
 * getline.cpp
 */
#include <cstdio>

#include <string>

using namespace std;

extern "C" int _fastcall getline(char* line, const int max) {
	int i = 0;
	for (i = 0; max > i && '\n' != (line[i] = getc(stdin)); i++);
	if (i < max)
		//eat the newline
		line[i--] = '\0';
	else
		line[i - 1] = '\0';
	return i;
}

extern int _fastcall getline(string& line) {
	int i = 0;
	for (i = 0;
		'\n' != (line[i] = getc(stdin));
		line.resize((++i) + 1));
	//eat the newline
	line[i--] = '\0';
	return i;
}