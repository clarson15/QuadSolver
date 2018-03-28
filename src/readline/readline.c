#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "readline.h"

FILE* logfile;
/*
currently this function only returns 0 (no errors) but err is reserved for any errors.
*/
int readline(FILE *stream, int n, char* buf)
{
	int err = 0, amt_read = 0;
	if((logfile = fopen("logfile", "a+")) == NULL)
		fprintf(stderr, "Failed to open log file, continuing.");
	else
		fprintf(logfile, "readline:\nn = %d\n", n);
	amt_read = strlen(fgets(buf, n, stream)); //read n characters from stdin
	if(amt_read-1 > 0)
		buf[amt_read-1] = 0; //null terminator
	
	if(logfile != NULL){
		fprintf(logfile, "amt_read = %d. buf = %s\nExiting readline\n", amt_read, buf);
		fflush(logfile);
		fclose(logfile);
	}
	return err;
}

