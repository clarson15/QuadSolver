#include <CUnit/Basic.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "readline.h"

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }
void readline_test(void);

int main (void) {
	// Initialize CUnit
	CU_pSuite pSuite = NULL;
	if (CUE_SUCCESS != CU_initialize_registry() ) {
		return CU_get_error();
	}

	// Create a test suite
	pSuite = CU_add_suite("readline", init_suite, clean_suite);
	if (pSuite == NULL) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Add the tests.
	if (CU_add_test(pSuite, "readline_test", readline_test) == NULL) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	puts("");
}

void readline_test (void) {
	FILE *file = fopen("dummy", "r");
	char buf[250], buf2[250];
	readline(file, 250, buf);
	CU_ASSERT_EQUAL(strcmp(buf, "hello"), 0);
	readline(file, 250, buf2);
	CU_ASSERT_EQUAL(strcmp(buf2, "world"), 0);
}
