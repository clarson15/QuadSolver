#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "validate/validate.h"
#include "readline/readline.h"

//Prototypes for functions to add in link stage
extern int qsolve(float a, float b, float c, float* x1, float* x2);
extern int foutput(char* buf, int stream);

int main(int argc, char* argv[]){
	char buffer[120];
	float a, b, c, x1, x2;
	int ret = 0;
	puts("Please input coefficients seperated by spaces:");
	ret = readline(stdin, 120, buffer);
	ret = validate(buffer, &a, &b, &c);
	ret = qsolve(a, b, c, &x1, &x2);
	//todo: output info to buffer before foutput call
	sprintf(buffer, "x1 = %f, x2 = %f", x1, x2);
	ret = foutput(buffer, STDOUT_FILENO);
	return ret;
}
