qsolve.c:
Take three inputs: a, b, and c as a, b, and c from the quadratic equation and find all real number solutions. 

Prototype:
int qsolve(float a, float b, float c, float* x1, float* x2);

Where the return value is if it succeeded (success = 1), a, b, and c are the coefficients of an equation of the form ax^2 + bx + c = 0, and x1 and x2 are solutions of the former equation. 
If an error occurs, a will contain an error number that will be defined in qsolve.c
