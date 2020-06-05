
#include <stdio.h>
#include <string.h>

#include "../src/util/LinkedList.h"
#include "Test.h"

void test_append();
void test_push();
void test_pop();

int main()
{

	test_append();
	test_push();
	test_pop();

}

void test_append()
{

	const int n = 16;
	init_test_suite(2 * n, "Append", "Testing Functionality of append utilities");

	// Initialize list to perform tests on
	LinkedList* list = ll_init();
	size_t elem_size = 4;

	// Attempt to `append` values
	for(int i = 0; i < n; i++)
	{
		// Append a value to list
		int val = i*i;
		ll_append(list, &val, elem_size);
		
		// Test
		assert_eq_int(val, * (int*) list->tail->payload);
		assert_eq_int(i + 1, list->length);
	}

	// Clear list from memory
	ll_dispose(list);
	terminate_test_suite();

}

void test_push()
{

	const int n = 16;
	init_test_suite(n * 2, "Push", "Testing Functionality of pushing values to front of list");

	// Initialize
	LinkedList* list = ll_init();
	size_t elem_size = 4;

	// Attempt to `push` values
	for(int i = 0; i < n; i++)
	{

		// Push value
		int val = i*i;
		ll_push(list, &val, elem_size);

		// Test
		assert_eq_int(val, * (int*) list->head->payload);
		assert_eq_int(i + 1, list->length);

	}

	ll_dispose(list);
	terminate_test_suite();

}

void test_pop()
{

	const int n = 16;
	init_test_suite(2 * n, "Pop", "Testing functionality of popping values from the front of list");

	// init
	LinkedList* list = ll_init();
	size_t elem_size = 4;

	// Populate list
	for(int i = 0; i < n; i++)
	{
		int val = i * i;
		ll_append(list, &val, elem_size);
	}

	for(int i = 0; i < n; i++)
	{
		int out;
		ll_pop(list, &out);

		assert_eq_int(i*i, out);
		assert_eq_int(n - i - 1, list->length);
	}

	ll_dispose(list);
	terminate_test_suite();

}
