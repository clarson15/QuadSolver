/*
*  Adding test with a = 0 meaning the equation isn't quadratic.
*  I'm pretty sure the current qsolve.c doesn't adequately handle
*  this situation.
*/

void qsolve_test_nonquad_dis (void) {
	float x1, x2;
	float a = 0, b = 2.0f, c = 12.0f;
	int ret = qsolve(a, b, c, &x1, &x2);
}