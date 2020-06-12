
#include "Test.h"
#include "../src/Parser.h"
#include "../src/util/LinkedList.h"

#include <stdio.h>

void test_tokenizer();

int main()
{

    test_tokenizer();

}

void test_tokenizer()
{

    const int n = 5 + 8;
    init_test_suite(n, "Tokenizer", "Will tokenize a given string");

    // Setup test values
    char* expr1 = "1 + 1 * 1";
    char* tokens1[] = {"1", "+", "1", "*", "1"};

    LinkedList* list = ll_init();
    tokenize(expr1, list);

    char buffer[256];
    for(int i = 0; i < 5; i++)
    {
        ll_pop(list, buffer);
        assert_eq_str(tokens1[i], buffer);
    }

    char* expr2 = "1+2  - 5*11/420";
    char* tokens2[] = {"1", "+", "2", "-", "5", "*", "11", "/", "420"};
    tokenize(expr2, list);
    
    for(int i = 0; i < 8; i++)
    {
        ll_pop(list, buffer);
        assert_eq_str(tokens2[i], buffer);
    }

    terminate_test_suite();

}
