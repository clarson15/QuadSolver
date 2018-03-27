#include <stdio.h>
#include <string.h>
#include <unistd.h>

int foutput(char* buf, int stream);
FILE* logfile;

int foutput(char* buf, int stream){
	if((logfile = fopen("logfile", "a+")) == NULL)
		fprintf(stderr, "Failed to open log file, continuing.");
	else
		fprintf(logfile, "foutput:\nwrite to %d. buffer = \"%s\"\n", stream, buf);

	int err = 0, amt_write = 0;
	amt_write = write(stream, buf, strlen(buf));
	write(stream, "\n", 1);
	
	if(logfile != NULL){
		fprintf(logfile, "Wrote %d bytes to output stream. Exiting foutput\n", amt_write);
		fflush(logfile);
		fclose(logfile);
	}
	return err;
}
