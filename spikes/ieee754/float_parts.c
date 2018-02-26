#include <stdio.h>

typedef union {
  float f;
  struct {
	unsigned int mantissa : 23;
	unsigned int exponent : 8;
	unsigned int sign     : 1;
  } parts;
} float_cast;

int main (void) {
	float input;
	printf("Enter a floating point number (note: no validation done in this spike):\n");
	scanf("%f", &input);

	printf("Parts for: %f\n", input);

	float_cast d1 = { .f = input };
	printf("sign = %x\nexponent = %x\nmantissa = %x\n", d1.parts.sign, d1.parts.exponent, d1.parts.mantissa);

	return 1;
}
