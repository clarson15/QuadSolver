#include <CUnit/Basic.h>
#include <stdio.h>

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }
int max(int, int);
void max_test(void);

int main (void) {
	// Initialize CUnit
	CU_pSuite pSuite = NULL;
	if (CUE_SUCCESS != CU_initialize_registry() ) {
		return CU_get_error();
	}

	// Create a test suite
	pSuite = CU_add_suite("max_test_suite", init_suite, clean_suite);
	if (pSuite == NULL) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Add the tests.
	if (CU_add_test(pSuite, "max_test", max_test) == NULL) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	puts("");
}

void max_test (void) {
	CU_ASSERT(max(1,2) == 2);
	CU_ASSERT(max(4,3) == 4);
}

int max(int i1, int i2) {
	return i1 > i2? i1 : i2;
}
