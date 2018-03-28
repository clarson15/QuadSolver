#include <CUnit/Basic.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "validate.h"

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }
void validation_test (void);
void validation_test_zero (void);

int main (void) {
	// Initialize CUnit
	CU_pSuite pSuite = NULL;
	if (CUE_SUCCESS != CU_initialize_registry() ) {
		return CU_get_error();
	}

	// Create a test suite
	pSuite = CU_add_suite("validate", init_suite, clean_suite);
	if (pSuite == NULL) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Add the tests.
	if ((CU_add_test(pSuite, "validation_test", validation_test) == NULL)
			| (CU_add_test(pSuite, "validation_test_zero", validation_test_zero) == NULL)) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	puts("");
}

void validation_test (void) {
	int success = 16384 | 8192 | 4096;
	char *str = "104.68 08.36 2e2";
	float a, b, c;
	int ret = validate(str, &a, &b, &c);

	CU_ASSERT_EQUAL(a, 104.68f);
	CU_ASSERT_EQUAL(b, 8.36f);
	CU_ASSERT_EQUAL(c, 200.0f);
	CU_ASSERT_EQUAL(ret, success);
}

void validation_test_zero (void) {
	int success = 4 | 2 | 4096;
	char *str = "0 0.00 1.2e3";
	float a, b, c;
	int ret = validate(str, &a, &b, &c);

	CU_ASSERT_EQUAL(a, 0.0f);
	CU_ASSERT_EQUAL(b, 0.0f);
	CU_ASSERT_EQUAL(c, 1200.0f);
	CU_ASSERT_EQUAL(ret, success);
}
