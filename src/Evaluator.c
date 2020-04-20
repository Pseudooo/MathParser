#include "Evaluator.h"

#include <string.h>
#include <math.h>

#include "util/Numeric.h"
#include "util/LinkedList.h"

#include <stdio.h>

int is_operator(char* str);
void perform_operation(LinkedList* stack, char* op);

int ADD(int x1, int x2);
int SUB(int x1, int x2);
int MUL(int x1, int x2);
int DIV(int x1, int x2);
int EXP(int x1, int x2);

const int OP_COUNT = 5;
const char* ops_str[] = {"+", "-", "*", "/", "^"};
const int (*ops[]) (int x1, int x2) = {ADD, SUB, MUL, DIV, EXP};

/**
	Will evaluate a provided postfix expression and place
	the result into the integer located at `dest`
	1 -> Success
	0 -> Invalid Token encountered
*/
int eval_postfix(const char* postfix_expr, int* dest)
{

	LinkedList* stack = ll_init();

	// Make a "local" copy of the string to tokenize
	char str[strlen(postfix_expr) + 1];
	strcpy(str, postfix_expr);

	// Iter over all tokens (terms)
	char* token = strtok(str, " ");
	while(token != NULL)
	{	
		
		if(is_number(token))
		{
			// All numbers just get pushed to the stack
			ll_push(stack, token);
		}
		else if(is_operator(token))
		{
			// Operators must be evaluated with top 2 stack values
			perform_operation(stack, token);
		}
		else
		{
			// Invalid Token reached
			return 0;
		}

		// Continue to next token
		token = strtok(NULL, " ");
	}

	if(stack->length != 1)
	{
		// Stack should only have one element after successful eval
		return 0;
	}

	// Migrate result to `dest` 
	char final[16];
	ll_pop(stack, final);
	from_str(final, dest);

	// Free stack from memory
	ll_dispose(stack);

	return 1;

}

/**
	Will determine if a provided string is an operator or not
*/
int is_operator(char* str)
{

	// Perform linear search on operator list
	for(int i = 0; i < OP_COUNT; i++)
		if(strcmp(str, ops_str[i]) == 0)
			return 1;

	return 0;

}

/**
	Given an operator as a string perform that operation
	on the values currently retained in the stack
*/
void perform_operation(LinkedList* stack, char* op)
{

	// init vars
	int x1, x2;
	char buff[16];

	// Take x1 & x2 from the stack
	ll_pop(stack, buff); from_str(buff, &x2);
	ll_pop(stack, buff); from_str(buff, &x1);

	// Find index for given operation
	int ans;
	for(int i = 0; i < OP_COUNT; i++)
	{
		if(strcmp(op, ops_str[i]) == 0)
		{
			// Operation found, compute and add to stack
			ans = ops[i](x1, x2);
			break;
		}
	}

	// Push result back to stack
	to_str(ans, buff);
	ll_push(stack, buff);

}

/**
	The following are the definitions for the operation functions
*/

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

int EXP(int x1, int x2)
{
	return (int) pow(x1, x2);
}
