#include <stdio.h>

#define SHIFT_EXP 23

char is_normalized(float *f);

int main (void) {
	float f;

	printf("Enter a floating point number (note: no validation done):");

	scanf("%f", &f);

	printf("Entered float: %f\n", f);

	printf("Is normalized? %s\n", is_normalized(&f) ? "yes" : "no");
}

char is_normalized(float *f) {
	unsigned int *ptr = (unsigned int *)f;
	unsigned int exp = (*ptr >> SHIFT_EXP) & 0xFF;

	return exp >= 0x7f;
}
