#include <stdio.h>
#include <math.h>

int qsolve(float a, float b, float c, float* x1, float* x2);
FILE* logfile;

int qsolve(float a, float b, float c, float* x1, float* x2)
{
	if((logfile = fopen("logfile", "a+")) == NULL)
		fprintf(stderr, "Failed to open log file, continuing.");
	else
		fprintf(logfile, "qsolve:\na = %f b = %f c = %f\n", a, b, c);
	int ret = 1;
	float d = b * b - 4 * a * c;

	if(d > 0)
	{
		*x1 = (-b + sqrt(d)) / (2 * a);
		*x2 = (-b - sqrt(d)) / (2 * a);
	}
	else if(d == 0)
	{
		*x1 = -b / (2 * a);
		*x2 = *x1;
	}
	else
	{
		ret = 0;
	}
	if(logfile != NULL){
		fprintf(logfile, "x1 = %f. x2 = %f. determinant = %f.\nExiting validate\n", *x1, *x2, d);
		fflush(logfile);
		fclose(logfile);
	}
	return ret;
}
