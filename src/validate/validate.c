#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
Return code:
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

int validate(char* str, float* a, float *b, float *c){
	int ret = 0, aclassify, bclassify, cclassify;
	sscanf(str, "%f %f %f", a, b, c);
	aclassify = fpclassify(*a);
	bclassify = fpclassify(*b);
	cclassify = fpclassify(*c);
	switch(aclassify){
	case FP_INFINITE:
		ret |= 256;
		break;
	case FP_NAN:
		ret |= 32;
		break;
	case FP_NORMAL:
		ret |= 16384;
		break;
	case FP_SUBNORMAL:
		ret |= 2056;
		break;
	case FP_ZERO:
		ret |= 4;
		break;
	default:
		break;
	}
	switch(bclassify){
	case FP_INFINITE:
		ret |= 128;
		break;
	case FP_NAN:
		ret |= 16;
		break;
	case FP_NORMAL:
		ret |= 8192;
		break;
	case FP_SUBNORMAL:
		ret |= 1024;
		break;
	case FP_ZERO:
		ret |= 2;
		break;
	default:
		break;
	}
	switch(cclassify){
	case FP_INFINITE:
		ret |= 64;
		break;
	case FP_NAN:
		ret |= 8;
		break;
	case FP_NORMAL:
		ret |= 4096;
		break;
	case FP_SUBNORMAL:
		ret |= 512;
		break;
	case FP_ZERO:
		ret |= 1;
		break;
	default:
		break;
	}
	return ret;
}
