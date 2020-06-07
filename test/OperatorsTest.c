
#include "../src/util/Operators.h"
#include "Test.h"

void test_is_operator();

int main()
{

    test_is_operator();

}

void test_is_operator()
{

    const int n = 8;
    init_test_suite(n, "Is Operator Check", "Checking if a given string is an Operator");

    // Check all valid operators return true (1)
    char* valid_operators[] = {"+", "-", "*", "/"};
    for(int i = 0; i < 4; i++)
        assert_eq_int(1, is_operator(valid_operators[i]));

    // Check possible invalid operators                       B)
    char* invalid_operators[] = {"foo", "bar", "top", "420"};
    for(int i = 0; i < 4; i++)
        assert_eq_int(0, is_operator(invalid_operators[i]));

    terminate_test_suite();

}
