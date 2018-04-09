/*
*  Adding in separate file because I don't know how to add correctly
*  to the test file already made. These test for things like strings
*  with too many or too little numbers, and includes one with non-numbers.
*  I don't believe validate has any way to handle these in its current state.
*/
void validation_test_string (void) {
	char *str = "101 87.9 abcde"
	float a, b, c;
	int ret = validate(str, &a, &b, &c);
}

void validation_test_short (void) {
	char *str = "22.3 45.8"
	float a, b, c;
	int ret = validate(str, &a, &b, &c);
}

void validation_test_long (void) {
	char *str = "15 97.9 303.2 405"
	float a, b, c;
	int ret = validate(str, &a, &b, &c);
}