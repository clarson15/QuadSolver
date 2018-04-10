#include <CUnit/Basic.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "foutput.h"

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }
void output_test (void);

int main (void) {
	// Initialize CUnit
	CU_pSuite pSuite = NULL;
	if (CUE_SUCCESS != CU_initialize_registry() ) {
		return CU_get_error();
	}

	// Create a test suite
	pSuite = CU_add_suite("output", init_suite, clean_suite);
	if (pSuite == NULL) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Add the tests.
	if (CU_add_test(pSuite, "output_test", output_test) == NULL) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	puts("");
}

void output_test (void) {
	int fd = open("testfile", O_WRONLY | O_CREAT, S_IRWXU);
	foutput("hello", fd);
	close(fd);

	FILE *f = fopen("testfile", "r");
	char buf[100];
	fgets(buf, 100, f);
	fclose(f);

	CU_ASSERT_EQUAL(strcmp(buf, "hello\n"), 0);
}
