#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// Takes the return value from fpclassify and converts it into a string that can be printed.
char *get_fp_classification (int classnum) {
	// Create the classification table. Note that this implementation may 
	// change depending on platform depending on the #DEFINEs used for FP_INFINITE, etc.
	char *class[6];

	class[FP_INFINITE] = "Infinite";
	class[FP_NAN] = "NaN";
	class[FP_NORMAL] = "Normalized";
	class[FP_SUBNORMAL] = "Denormalized";
	class[FP_ZERO] = "Zero";

	return class[classnum];
}

int main (void) {
	float f;
	puts("Enter a floating point number:");
	scanf("%f", &f);

	printf("Information for floating point number %f\n", f);

	printf("Normal: %s\n", isnormal(f) ? "yes" : "no"); 
	printf("Inf: %s\n", isinf(f) ? "yes" : "no");
	printf("NaN: %s\n", isnan(f) ? "yes" : "no");
	printf("Classify: %s\n", get_fp_classification(fpclassify(f)));

	return EXIT_SUCCESS;
}
