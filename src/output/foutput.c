#include <stdio.h>
#include <string.h>
#include <unistd.h>

int foutput(char* buf, int stream);

int foutput(char* buf, int stream){
	write(stream, buf, strlen(buf));
	return 0;
}
