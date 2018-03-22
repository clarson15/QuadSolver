#include <string.h>
#include <stdio.h>
#include <unistd.h>

int readline(int n, char* buf);

/*
currently this function only returns 0 (no errors) but err is reserved for any errors.
*/
int readline(int n, char* buf)
{
	int err = 0;

	err = read(STDIN_FILENO, buf, n); //read n characters from stdin
	buf[err] = 0; //null terminator

	return err;
}

