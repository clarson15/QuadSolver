#include <stdio.h>
#include <stdlib.h>

//Simple program that sets a,b, and c to
//command-line arguments and prints out results
int main(int argc, char * argv[])
{
	float a = atof(argv[1]);
	float b = atof(argv[2]);
	float c = atof(argv[3]);


	//To show numbers were read in correctly
	printf("\na:%f\nb:%f\nc:%f", a, b, c);
}

