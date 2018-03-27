#include <stdio.h>

// the sign bit is the first bit, so will need to shift 31 to get to it.
#define SHIFT_SIGN 31
#define SHIFT_EXP  23

int main (void) {
	float input;
	printf("Enter a floating point number (note: no validation is done in this spike):\n");
	scanf("%f", &input);

	printf("Parts for :%f\n", input);

	// Create a pointer to the float input.
	unsigned int *ptr = (unsigned int *) &input;

	// Shift the pointer and mask 1 bit to get the sign bit.
	unsigned int sign = (*ptr >> SHIFT_SIGN) & 0x01;
	// Shift the pointer and mask 8 bits to get the exponent.
	unsigned int exp = (*ptr >> SHIFT_EXP) & 0xFF;
	// Mask the last 23 bits for the mantissa.
	unsigned int mantissa = *ptr & 0x7FFFFF;

	// Print the results.
	printf("sign = %x\nexponent = %x\nmantissa = %x\n", sign, exp, mantissa);
}
