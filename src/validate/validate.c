//dummy file to test makefiles
#include <stdio.h>

int validate(char* str, float* a, float *b, float *c){
	int err = 1;
	sscanf(str, "%f %f %f", a, b, c);
	//todo: more validation on floats before returning an error code
	return err;
}
