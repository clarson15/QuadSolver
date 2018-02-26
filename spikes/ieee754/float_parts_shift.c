#include <stdio.h>

#define SHIFT_SIGN 31
#define SHIFT_EXP  23

int main (void) {
	float input;
	printf("Enter a floating point number (note: no validation is done in this spike):\n");
	scanf("%f", &input);

	printf("Parts for :%f\n", input);

	unsigned int *ptr = (unsigned int *) &input;

	unsigned int sign = (*ptr >> SHIFT_SIGN) & 0x01;
	unsigned int exp = (*ptr >> SHIFT_EXP) & 0xFF;
	unsigned int mantissa = *ptr & 0x7FFFFF;

	printf("sign = %x\nexponent = %x\nmantissa = %x\n", sign, exp, mantissa);
}
