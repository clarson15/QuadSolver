#include <stdio.h>
#include "qsolve.h"

int main(int argc, char* argv[]){
	float x1, x2;
	qsolve(1.0, 10.0, 16.0, &x1, &x2);
	qsolve(1.0, 2.0, 1.0, &x1, &x2);
	return 0;
}
