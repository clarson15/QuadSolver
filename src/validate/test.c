#include <stdio.h>

extern int validate(char*, float*, float*, float*);
/*
Return code for validate:
flip the appropriate bit depending on properties of each float:
(a - b - c respectively, assuming 32-bit integers but also works on 16-bit)
00000000000000000[Normal][Denormal][Infinite][[NaN][Zero]
Examples:
a, b, c are all non-zero normalized floats:
00 000 000 000 000 000 111 000 000 000 000
a and b are zero:
00 000 000 000 000 000 000 000 000 000 110
a and b are normal but c is infinite:
00 000 000 000 000 000 110 000 001 000 000
*/


int main(int argc, char* argv[]){
	float a, b, c;
	int ret = 0;
	char str[80];
	sprintf(str, "01.2352 218.320 4238.302");
	ret = validate(str, &a, &b, &c);
	printf("%d: %s: %f %f %f\n", ret, str, a, b, c);
	sprintf(str, "102.202 -2320.002 10283.20");
	ret = validate(str, &a, &b, &c);
	printf("%d: %s: %f %f %f\n", ret, str, a, b, c);
	return 0;
}
