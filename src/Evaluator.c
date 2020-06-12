
#include <string.h>
#include <stdio.h>

#include "Evaluator.h"

#include "util/Numeric.h"
#include "util/Operators.h"

int perform_operation(LinkedList* stack, char* op);

/*
	Function to evaluate a given postfix expression
	result will be placed in dest
		0 -> Invalid Token
		1 -> Successful evaluation
	   -1 -> Invalid Expression
*/
int eval_postfix(const char* postfix_expr, int* dest)
{

	LinkedList* stack = ll_init();

	// Make a local copy of the expression to tokenize
	char str[strlen(postfix_expr) + 1];
	strcpy(str, postfix_expr);

	char* token = strtok(str, " ");
	while(token != NULL)
	{
		// All integer valuesare added to the stack
		if(is_integer(token))
		{
			int value = from_str(token);
			ll_push(stack, &value, 4);
		}
		// All operators are to be performed on the stack
		else if(is_operator(token))
		{
			if(!perform_operation(stack, token))
				return -1;
		}
		// Non-integers and non-operators are invalid tokens
		else
		{
			return 0;
		}

		// Next token
		token = strtok(NULL, " ");
	}

	// Stack should only contain final result
	if(stack->length != 1)
		return -1;

	// Take result from stack and clear it
	int result;
	ll_pop(stack, &result);
	ll_dispose(stack);

	*dest = result;

	return 1;

}

/*
	Helper function to perform a given operator on the
	stack
		0 -> Invalid Stack
		1 -> Successful Operation
*/
int perform_operation(LinkedList* stack, char* op)
{

	if(stack->length < 2)
		return 0;

	int x1, x2;
	ll_pop(stack, &x2);
	ll_pop(stack, &x1);

	// Compute answer given string operator
	int ans = evaluate_operator(op, x1, x2);

	ll_push(stack, &ans, 4);
	return 1;

}