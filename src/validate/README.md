validate.c:
Take a string and validate the input. Parse floats into a, b, and c.

prototype:
int validate(char* buf, float* a, float* b, float* c);

Where the return value is if it succeeded (success = 1), buf is a pointer to the user input, a, b, and c should be pointers to floats to store the three parsed values. 
If an error occurrs, an error code will be stored in buf which should be defined in validate.c
