
#include "../src/util/Operators.h"
#include "Test.h"

void test_is_operator();
void test_evaluate_operator();

int main()
{

    test_is_operator();
    test_evaluate_operator();

}

void test_is_operator()
{

    const int n = 8;
    init_test_suite(n, "Is Operator", "Checking if a given string is an Operator");

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

void test_evaluate_operator()
{

    const int n = 4;
    const int sols[] = {2, 0, 9, 1};

    init_test_suite(n, "Operator Evalation", "Testing values given when evaluating operators");
    for(int i = 0; i < n; i++)
        assert_eq_int(sols[i], evaluate_operator(OPERATOR_STR[i], i + 1, i + 1));


    terminate_test_suite();

}
