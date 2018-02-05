foutput.c:
Take a string and output it to an output stream. 

prototype:
int foutput(char* buf, int stream);

Where the return value is for error checking (success = 1), buf is the pointer to a string to be printed, and stream is the stream ID to output to (STDOUT, STDERR, ...). 
If an error occurs, buf will contain an error number that should be defined in validate.c
