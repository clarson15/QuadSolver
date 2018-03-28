#include <stdio.h>
#include <fnctl.h>
#include "readline.h"

int main(int argc, char* argv[]){
	char buf[120];
	int file = open("dummy", O_RDONLY);
	readline(file, 120, buf);
	printf("%s\n", buf);
	return 0;
}
