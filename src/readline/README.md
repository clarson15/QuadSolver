readline.c:
Reads input from command line/user. Can accept either standard or scientific notation. 

prototype:
int readline(int n, char* buf);

Where the return value is for error checking (success = 1), n is the amount of characters to read, and buf is a pointer to the container. 
If an error occurs, buf will contain an error number that should be defined in readline.c
