
#include "Test.h"
#include "../src/Parser.h"
#include "../src/util/LinkedList.h"

#include <stdio.h>

void test_tokenizer();
void test_parse_infix_postfix_valid();
void test_parse_infix_postfix_invalid();

int main()
{

    test_tokenizer();
    test_parse_infix_postfix_valid();
    test_parse_infix_postfix_invalid();

}

void test_tokenizer()
{

    const int n = 4 + 3 + 9 + 12 + 9;
    init_test_suite(n, "Tokenizer", "Will tokenize a given string");

    const char* test_exprs[] =
    {
        "1 + 1",
        "1 + 2 - 3 * 5 / 6",
        "(((1 + 2) * 3) / 4)",
        "1    +(2 * 3   ) - 2"
    };
    const char* expr_toks[][13] =
    {
        {"1", "+", "1"},
        {"1", "+", "2", "-", "3", "*", "5", "/", "6"},
        {"(", "(", "(", "1", "+", "2", ")", "*", "3", ")", "/", "4", ")"},
        {"1", "+", "(", "2", "*", "3", ")", "-", "2"}
    };
    const int expr_toks_count[] = {3, 9, 13, 9};

    for(int i = 0; i < 4; i++)
    {
        LinkedList* tokens = ll_init();
        tokenize(test_exprs[i], tokens);

        char buffer[32];
        for(int j = 0; j < expr_toks_count[i]; j++)
        {
            ll_pop(tokens, buffer);
            assert_eq_str(expr_toks[i][j], buffer);
        }

        assert_eq_int(1, ll_isempty(tokens));

        ll_dispose(tokens);
    }

    terminate_test_suite();

}

void test_parse_infix_postfix_valid()
{

    const int n = 4;
    init_test_suite(n, "Infix to Postfix", "Converting an Infix Expression to Postfix");

    char* infix_exprs[] =
    {
        "1 + 1",
        "420 * 120 + 1",
        "69 + 69 * 69 - 69 / 69",
        "123456 + (1 - 2 * (3 / 2 * 3 + (2 - 2 * 2)))"
    };
    const const char* postfix_exprs[] =
    {
        "1 1 +",
        "420 120 * 1 +",
        "69 69 69 * + 69 69 / -",
        "123456 1 2 3 2 / 3 * 2 2 2 * - + * - +"
    };

    char buffer[512];
    for(int i = 0; i < 512; i++)
        buffer[i] = 0;

    for(int i = 0; i < n; i++)
    {
        parse_infix_postfix(infix_exprs[i], buffer);
        assert_eq_str(postfix_exprs[i], buffer);
    }

    terminate_test_suite();

}

void test_parse_infix_postfix_invalid()
{

    const int n = 2;
    init_test_suite(n, "Invalid Expression Parsing", "Attempting to parse an invalid expression");

    char* infix_exprs[] =
    {
        "1 + 1",
        "1 1 a",
        "1 + ( 1 - 2"
    };
    int results[] = {1 ,-1, 0};

    char buffer[512];
    for(int i = 0; i < n; i++)
        assert_eq_int(results[i], parse_infix_postfix(infix_exprs[i], buffer));

    terminate_test_suite();

}
