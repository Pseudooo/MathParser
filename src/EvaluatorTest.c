#include <stdio.h>

#include "Evaluator.h"

int main()
{

	int test_cases = 0, total = 4;

	const const char* exprs[] =
	{
		"1 1 +",
		"2 3 *",
		"2 3 ^ 5 4 * / 10 +",
		"1 3 * 2 + 6 -"
	};

	const int sols[] =
	{
		2, 6, 10, -1
	};


	// Run each test case
	for(int i = 0; i < total; i++)
	{
		printf("Running Test Case [%02d/%02d]\n", i+1, total);

		printf(">>> Evaluating: %s\n", exprs[i]);
		printf(">>> Expected: %d\n", sols[i]);
		int res; eval_postfix(exprs[i], &res);
		printf(">>> Actual: %d\n", res);
		if(res != sols[i])
			printf(">>>>>> FAILURE\n");
		printf("\n");
	}

}