#include <stdio.h>
#include <math.h>
#include "qsolve.h"

FILE* logfile;

int qsolve(float a, float b, float c, float* x1, float* x2)
{
	float d;
	if((logfile = fopen("logfile", "a+")) == NULL)
		fprintf(stderr, "Failed to open log file, continuing.");
	else
		fprintf(logfile, "qsolve:\na = %f b = %f c = %f\n", a, b, c);
	int ret = 0;
	if(a == 0 || fpclassify(a) == FP_INFINITE){
		fprintf(logfile, "a = 0 or a = inf, solution not quadratic.\n");
		ret = 16;
	}
	else{
		d = b * b - 4 * a * c;
		if((fpclassify(d) == FP_INFINITE) || (fpclassify(d) == FP_NAN)){
			ret = 1; //if discriminant is infinite or NaN, stop computing.
		}
		else if(d > 0)
		{
			*x1 = (-b + sqrt(d)) / (2 * a);
			*x2 = (-b - sqrt(d)) / (2 * a);
		}
		else if(d == 0)
		{
			*x1 = -b / (2 * a);
			*x2 = *x1;
		}
		else{
			ret = 8;
		}
		if(ret == 0){
			if((fpclassify(*x1) == FP_INFINITE) || (fpclassify(*x1) == FP_NAN)){
				ret |= 2;
			}
			if((fpclassify(*x2) == FP_INFINITE) || (fpclassify(*x2) == FP_NAN)){
				ret |= 4;
			}
		}
	}
	if(logfile != NULL){
		fprintf(logfile, "x1 = %f. x2 = %f. discriminant = %f. ret = %d\nExiting validate\n", *x1, *x2, d, ret);
		fflush(logfile);
		fclose(logfile);
	}
	return ret;
}
