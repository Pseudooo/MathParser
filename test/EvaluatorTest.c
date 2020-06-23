#include <stdio.h>

#include "../src/Evaluator.h"
#include "Test.h"

void test_evaluator_valid();
void test_evaluator_invalid();

int main()
{

	test_evaluator_valid();
	test_evaluator_invalid();

}

void test_evaluator_valid()
{

	const int n = 3;
	init_test_suite(n, "Testing Valid Cases", "Testing valid postfix expressions");

	char* exprs[] =
	{
		"1 1 +",
		"2 3 *",
		"1 3 * 2 + 6 -"
	};
	int sols[] = {2, 6, -1};

	for(int i = 0; i < n; i++)
	{
		int result;
		eval_postfix(exprs[i], &result);
		assert_eq_int(sols[i], result);
	}

	terminate_test_suite();

}

void test_evaluator_invalid()
{

	const int n = 3;
	init_test_suite(n, "Testing Invalid Cases", "Testing Invalid Postfix Expressions");

	char* exprs[] =
	{
		"1 9 +",
		"1 9 a",
		"1 + -"
	};
	int results[] = {1, 0, -1};

	int result;
	for(int i = 0; i < n; i++)
		assert_eq_int(results[i], eval_postfix(exprs[i], &result));

	terminate_test_suite();

}
