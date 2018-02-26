#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char is_float (const char *s, float *dest) {
	if (s == NULL) return 0;
	
	char *end;
	*dest = (float) strtod(s, &end);

	if (s == end) return 0;

	while (isspace((unsigned char) *end)) {
		end++;
	}

	return end == '\0';
}

void test (const char *s) {
	float x;
	printf("Test(\"%s\"):\n", s ? s : "NULL");
	if (is_float(s, &x)) {
		printf("It's a float\n");
	} else {
		printf("It's not a float\n");
	}
}

int main (void) {
	test("");
	test(NULL);
	test("55");
	test("123.x4");
	test("four");
	test("11.11");

	return EXIT_SUCCESS;
}
