#include <stdio.h>
#include <math.h>

int qsolve(float a, float b, float c, float* x1, float* x2);

int qsolve(float a, float b, float c, float* x1, float* x2)
{
	int ret = 1;
	int d = b * b - 4 * a * c;

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
	return ret;
}
