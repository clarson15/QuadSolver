#include <stdio.h>

extern int validate(char*, float*, float*, float*);

int main(int argc, char* argv[]){
	float a, b, c;
	char str[80];
	sprintf(str, "01.2352 218.320 4238.302");
	validate(str, &a, &b, &c);
	printf("%s: %f %f %f\n", str, a, b, c);
	sprintf(str, "102.202 -2320.002 10283.20");
	validate(str, &a, &b, &c);
	printf("%s: %f %f %f\n", str, a, b, c);
	return 0;
}
