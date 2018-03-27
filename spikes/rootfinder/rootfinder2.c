#include <stdio.h>

// -1 = readLine failed
// -2 = parseLine failed
// -3 = quadSolve failed

int readLine(char *, size_t);

int main (void) {
	char buf[250];
	size_t len = 250;
	
	if(readLine(buf, len)) return -1;
	printf("%s\n", buf);

	return 1;
}

int readLine(char *buf, size_t len) {
	printf("%s\n", fgets(buf, len, stdin));
	return 0;
}
