#include <stdio.h>

extern int foutput(char* buf, int stream);

int main(int argc, char* argv[]){
	foutput("Test123", 1);
	return 0;
}
