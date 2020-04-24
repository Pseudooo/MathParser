
#include <stdio.h>
#include <string.h>

#include "../src/util/LinkedList.h"
#include "Test.h"

void test_append();

int main()
{

	test_append();

}

void test_append()
{

	const int n = 16;
	init_test_suite(2 * n, "Append", "Testing Functionality of append utilities");

	// Initialize list to perform tests on
	LinkedList* list = ll_init();
	size_t elem_size = 4;

	// Attempt to `append` 64 values
	for(int i = 0; i < n; i++)
	{
		int val = i*i;
		ll_append(list, &val, elem_size);
		
		// Ensure list is 
		assert_eq_int(val, * (int*) list->tail->payload);
		assert_eq_int(i + 1, list->length);
	}

	// Clear list from memory
	ll_dispose(list);
	terminate_test_suite();

}
