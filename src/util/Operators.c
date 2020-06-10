
#include "Operators.h"
#include <string.h>

const int OPERATOR_COUNT = 4;
const char* OPERATOR_STR[] = {"+", "-", "*", "/"};
const int (*ops[]) (int x1, int x2) = {ADD, SUB, MUL, DIV};

/*
    Check if a given string is an operator or not, will
    return a truthy integer
*/
int is_operator(char* str)
{

    // Iterate over operators list and check if they equal
    for(int i = 0; i < OPERATOR_COUNT; i++)
        if(strcmp(OPERATOR_STR[i], str) == 0)
            return 1;
    
    // Not found so not an operator
    // (That's been registered)
    return 0;

}

/*
    Given an operator string and two values will
    perform the given operation.

    Operator string is assumed to be valid
*/
int evaluate_operator(char* op, int x1, int x2)
{
    for(int i = 0; i < OPERATOR_COUNT; i++)
        if(strcmp(op, OPERATOR_STR[i]) == 0)
            return ops[i](x1, x2);
    return 0;    
}

// * * * * * * * * * * * * * 
// All operators are defined below

int ADD(int x1, int x2)
{
    return x1 + x2;
}

int SUB(int x1, int x2)
{
    return x1 - x2;
}

int MUL(int x1, int x2)
{
    return x1 * x2;
}

int DIV(int x1, int x2)
{
    return x1 / x2;
}
