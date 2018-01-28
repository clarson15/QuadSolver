#include <stdio.h>
#include <stdlib.h>

//Simple program that asks for user input for floats
//a,b, and c and prints out the results.
int main()
{
	float a;
	float b;
	float c;

	printf("Enter \"a\": ");
	scanf("%f", &a);
	printf("Enter \"b\": " );
	scanf("%f", &b);
	printf("Enter \"c\": " );
	scanf("%f", &c);

	//To show numbers were read in correctly
	printf("\na:%f\nb:%f\nc:%f", a, b, c);
}

