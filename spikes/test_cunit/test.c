#include "../cunit/cunit.h"

int max(int, int);

int main (void) {
	cunit_init();
	assert_eq("max1", max(0,1), 2);
	assert_eq("max2", max(55,2), 55);
	assert_eq("max3", max(100,100), 100);
}

int max(int i1, int i2) {
	return i1 > i2? i1 : i2;
}
