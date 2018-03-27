#include <stdio.h>

extern int qsolve(float, float, float, float*, float*);

int main(int argc, char* argv[]){
	float x1, x2;
	qsolve(1.0, 10.0, 16.0, &x1, &x2);
	qsolve(1.0, 2.0, 1.0, &x1, &x2);
	return 0;
}
