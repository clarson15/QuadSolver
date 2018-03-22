#include <stdio.h>

extern int readline(int n, char* buf);

int main(int argc, char* argv[]){
	char buf[120];
	readline(120, buf);
	printf("%s\n", buf);
	readline(120, buf);
	printf("%s\n", buf);
	return 0;
}
