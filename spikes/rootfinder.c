#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Program that uses a,b, and c to find roots x1 and x2
//This version just stores the values in x1 and x2 and prints results
void rootfinder(float a, float b, float c)
{
	float d = 0.0;
	float x1 = 0.0;
	float x2 = 0.0;
	char message[100];

	d = b * b - 4 * a * c;

    //Calculates real roots x1 and x2
    if(d > 0)
    {
        x1 = (-b +  sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);

        printf("x1:%f\nx2:%f", x1, x2);        
    }

    //Calculates in case of one real root.
    else if(d == 0) 
    {
        x1 = -b / (2 * a);
        x2 = x1;

        printf("x1:%f\nx2:%f", x1, x2);
    }
    //In case of no real roots
    else
    {
        printf("No real roots");
    }
}

//Tests the program
int main()
{

	rootfinder(1.0, 5.0, 6.0);
}

