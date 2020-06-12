
#include <stdio.h>
#include <string.h>

int TEST_CASES = 0;
int TEST_CASE = 0;

char* _name;
char* _desc;

void init_test_suite(int total_cases, char* name, char* desc)
{

	// Setup test environment
	TEST_CASES = total_cases;
	TEST_CASE = 0;
	_name = name;
	_desc = desc;

	// Print test message
	printf(" * * * \n");
	printf(" * * * STARTING NEW TEST SUITE\n");
	printf(" * * * Name: %s\n", _name);
	printf(" * * * Description: %s\n", _desc);;
	printf(" * * * Tests: %d\n", total_cases);
	printf(" * * * \n");

}

void assert_eq_int(int exp, int act)
{

	printf("Running Test [%d/%d]\n", ++TEST_CASE, TEST_CASES);

	if(act != exp)
	{
		printf(" * * * FAILURE\n");
		printf(" * * * Expected: %d\n", exp);
		printf(" * * * Actual: %d\n", act);
	}

}

void assert_eq_str(char* exp, char* act)
{

	printf("Running Test [%d/%d]\n", ++TEST_CASE, TEST_CASES);
	if(exp == act) return;

	if(exp == NULL || act == NULL)
		goto Failure;

	for(int i = 0;exp[i] != 0 && act[i] != 0;i++)
		if(exp[i] != act[i]) goto Failure;

	return;

	Failure:
	printf(" * * * FAILURE\n");
	printf(" * * * Expected: %s\n", exp);
	printf(" * * * Actual: %s\n", act);

}

void terminate_test_suite()
{
	printf(" * * *\n");
	printf(" * * * Terminating Test Suite\n");
	printf(" * * * Name: %s\n", _name);
	printf(" * * * Description: %s\n", _desc);;
	printf(" * * * Tests: %d\n", TEST_CASES);
	printf(" * * * \n");
}
