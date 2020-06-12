#include <stdio.h>

#include "../src/util/Numeric.h"
#include "Test.h"

void test_is_integer();
void test_from_str();
void test_to_str();

int main()
{

	test_is_integer();
	test_from_str();

}

void test_is_integer()
{

	const int n = 20;
	init_test_suite(n, "Integer Validation", "Check if provided string is a valid integer");

	// Check a set of known valid values                                                         B)
	char* valid_values[] = {"-123", "0123", "123", "-1", "-0", "0", "9", "0000123", "001200", "420"};
	for(int i = 0; i < 10; i++) // Will return 1 for valid int
		assert_eq_int(1, is_integer(valid_values[i]));

	char* invalid_values[] = {"foo", "bar", "-", "1234f", "-1234f", "pp", "-f6", "help", "me", "pl0x"};
	for(int i = 0; i < 10; i++)
		assert_eq_int(0, is_integer(invalid_values[i]));

	terminate_test_suite();

}

void test_from_str()
{

	const int n = 6;
	init_test_suite(n, "Parsing Integers", "Parsing a string representation of an integer");
	//                                             B)
	char* str_values[] = {"-123", "123", "0123", "420", "-8008512", "-0123"};
	int int_values[] = {-123, 123, 123, 420, -8008512, -123};
	for(int i = 0; i < n; i++)
		assert_eq_int(int_values[i], from_str(str_values[i]));

	terminate_test_suite();

}

void test_to_str()
{

	const int n = 5;
	init_test_suite(n, "Stringifying Integers", "Converting an Integer to a string");

	int int_values[] = {-123, 123, 420, -999999, 0};
	char* str_values[] = {"-123", "123", "420", "-999999", "0"};
	for(int i = 0; i < n; i++)
	{
		char str[32];
		to_str(int_values[i], str);

		assert_eq_str(str_values[i], str);
	}

	terminate_test_suite();

}