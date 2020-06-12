#include <stdio.h>

#include "../src/Evaluator.h"
#include "Test.h"

void test_evaluator_valid();

int main()
{

	test_evaluator_valid();

}

void test_evaluator_valid()
{

	const int n = 3;
	init_test_suite(n, "Testing Valid Cases", "Testing valid postfix expressions");

	const const char* exprs[] =
	{
		"1 1 +",
		"2 3 *",
		"1 3 * 2 + 6 -"
	};
	const int sols[] = {2, 6, -1};

	for(int i = 0; i < 3; i++)
	{
		int result;
		eval_postfix(exprs[i], &result);
		assert_eq_int(sols[i], result);
	}

	terminate_test_suite();

}