#include <CUnit/Basic.h>
#include <stdio.h>
#include "qsolve.h"

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }
void qsolve_test_pos_dis (void);
void qsolve_test_zero_dis (void);
void qsolve_test_neg_dis (void);

int main (void) {
	// Initialize CUnit
	CU_pSuite pSuite = NULL;
	if (CUE_SUCCESS != CU_initialize_registry() ) {
		return CU_get_error();
	}

	// Create a test suite
	pSuite = CU_add_suite("qsolve", init_suite, clean_suite);
	if (pSuite == NULL) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Add the tests.
	if ((CU_add_test(pSuite, "Positive Discriminant", qsolve_test_pos_dis) == NULL)
			| (CU_add_test(pSuite, "Zero Discriminant", qsolve_test_zero_dis) == NULL)
			| (CU_add_test(pSuite, "Negative Discriminant", qsolve_test_neg_dis) == NULL)) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	puts("");
}

void qsolve_test_pos_dis (void) {
	float x1, x2;
	float a = 1.0f, b = 10.0f, c = 16.0f;
	int ret = qsolve(a, b, c, &x1, &x2);

	CU_ASSERT_EQUAL(x1, -2.0f);
	CU_ASSERT_EQUAL(x2, -8.0f);
	CU_ASSERT_EQUAL(ret, 1);
}

void qsolve_test_zero_dis (void) {
	float x1, x2;
	float a = 1.0f, b = 2.0f, c = 1.0f;
	int ret = qsolve(a, b, c, &x1, &x2);

	CU_ASSERT_EQUAL(x1, -1.0f);
	CU_ASSERT_EQUAL(x2, -1.0f);
	CU_ASSERT_EQUAL(ret, 1);
}

void qsolve_test_neg_dis (void) {
	float x1, x2;
	float a = 2.0f, b=2.0f, c = 1.0f;
	int ret = qsolve(a, b, c, &x1, &x2);

	CU_ASSERT_EQUAL(ret, 0);
}
