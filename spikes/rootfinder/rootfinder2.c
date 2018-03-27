#include <stdio.h>
#include <math.h>

// run `echo $?` to get the return value from terminal.
// -1 = readLine failed
// -2 = parseLine failed
// -3 = quadSolve failed

int readLine(char *, size_t);
int parseLine(char *, float *, float *, float *);
int quadSolve(float *, float *, float, float, float);

int main (void) {
	char buf[250];
	size_t len = 250;
	
	puts("Enter 3 floating point numbers separated by spaces.");
	if(!readLine(buf, len)) return -1;
	printf("Got input: %s", buf);

	// now, define the floats a,b,c and parse them out of the line.
	float a, b, c;
	if (parseLine(buf, &a, &b, &c) < 3) return -2;
	printf("a: %f, b: %f, c: %f\n", a, b, c);

	// now, quadsolve.
	float x1, x2;
	if (!quadSolve(&x1, &x2, a, b, c)) return -3;
	printf("x1 = %f, x2 = %f\n", x1, x2);

	return 1;
}

int readLine(char *buf, size_t len) {
	// Read stdin into the buffer.
	buf = fgets(buf, len, stdin);
	// Return 0 if there is an error (fgets returns NULL), 1 otherwise.
	return buf != NULL;
}

// Parse a line of input for 3 floating point numbers.
// The return value is the number of floating points successfully assigned.
// If the function works fully, ret should be 3.
int parseLine(char *line, float *a, float *b, float *c) {
	int ret = sscanf(line, "%f %f %f", a, b, c);

	return ret;
}

// Will find the two roots, x1 and x2.
// Currently only positive real discriminants will work.
// returns 1 on success, 0 on failure.
int quadSolve(float *x1, float *x2, float a, float b, float c) {
	int ret; // placeholder variable for the return value.
	float discriminant = b*b - (4 * a * c);

	// Two real roots.
	if (discriminant > 0) {
		*x1 = (2 * c) / (-b - sqrt(discriminant));
		*x2 = (2 * c) / (-b + sqrt(discriminant));
		ret = 1;

	// One real root, multiplicity 2.
	} else if (discriminant == 0) {
		*x1 = *x2 = (2 * c) / -b;
		ret = 1;

	// discriminant < 0, two complex roots.
	} else {
		puts("Discriminant < 0. Not yet implemented.");
		ret = 0;
	}

	return ret;
}
