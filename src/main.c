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
	float a = 0.0f, b = 0.0f, c = 0.0f, x1 = 0.0f, x2 = 0.0f;
	int ret = 0;
	puts("Please input coefficients seperated by spaces:");
	ret = readline(stdin, 120, buffer);
	ret = validate(buffer, &a, &b, &c);
	//check the fp_classify values
	if((ret & 256) == 256){
		sprintf(buffer, "Error: Value A is infinite. Exiting.");
		foutput(buffer, STDOUT_FILENO);
		return 1;
	}
	else if((ret & 32) == 32){
		sprintf(buffer, "Error: Value A is NaN. Exiting.");
		foutput(buffer, STDOUT_FILENO);
		return 1;
	}
	else if((ret & 2056) == 2056){
		sprintf(buffer, "Warning: Value A is denormalized. This could lead to loss of precision.");
		foutput(buffer, STDOUT_FILENO);
	}
	else if((ret & 4) == 4){
		sprintf(buffer, "Warning: Value A is zero, so function isn't exponential.");
		foutput(buffer, STDOUT_FILENO);
		if((ret & 8192) == 8192){
			x1 = -c/b;
			sprintf(buffer, "x = %f", x1);
			foutput(buffer, STDOUT_FILENO);
		}
		else
			sprintf(buffer, "Error: Value B is invalid so there is no solution.");
		foutput(buffer, STDOUT_FILENO);
		return 1;
	}
	if((ret & 128) == 128){
		sprintf(buffer, "Error: Value B is infinite. Exiting.");
		foutput(buffer, STDOUT_FILENO);
		return 1;
	}
	else if((ret & 16) == 16){
		sprintf(buffer, "Error: Value B is NaN. Exiting.\n");
		foutput(buffer, STDOUT_FILENO);
		return 1;
	}
	else if((ret & 1024) == 1024){
		sprintf(buffer, "Warning: Value B is denormalized. This could lead to loss of precision.");
		foutput(buffer, STDOUT_FILENO);
	}
	else if((ret & 2) == 2){
		sprintf(buffer, "Warning: Value B is zero.");
		foutput(buffer, STDOUT_FILENO);
	}
	if((ret & 64) == 64){
		sprintf(buffer, "Error: Value C is infinite. Exiting.");
		foutput(buffer, STDOUT_FILENO);
		return 1;
	}	
	else if((ret & 8) == 8){
		sprintf(buffer, "Error: Value C is NaN. Exiting.");
		foutput(buffer, STDOUT_FILENO);
		return 1;
	}
	else if((ret & 512) == 512){
		sprintf(buffer, "Warning: Value C is denormalized. This could lead to loss of precision.");
		foutput(buffer, STDOUT_FILENO);
	}
	else if((ret & 1) == 1){
		sprintf(buffer, "Warning: Value C is zero.");
		foutput(buffer, STDOUT_FILENO);
	}
	ret = qsolve(a, b, c, &x1, &x2);
	if(ret == 0){
		sprintf(buffer, "x1 = %f, x2 = %f", x1, x2);
		ret = foutput(buffer, STDOUT_FILENO);
	}
	else if(ret == 1){
		sprintf(buffer, "Invalid discriminant while computing solutions.");
		ret = foutput(buffer, STDOUT_FILENO);
	}
	else if((ret & 0x6) != 0){
		sprintf(buffer, "Error: one or more solution is invalid.");
		ret = foutput(buffer, STDOUT_FILENO);
	}
	else if(ret == 8){
		sprintf(buffer, "Error: negative discriminant. Complex solutions.");
		ret = foutput(buffer, STDOUT_FILENO);
	}
	else{
		sprintf(buffer, "Unexpected return results from solver.");
		ret = foutput(buffer, STDOUT_FILENO);
	}
	return ret;
}
