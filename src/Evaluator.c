
#include <string.h>
#include <stdio.h>

#include "Evaluator.h"

#include "util/Numeric.h"
#include "util/Operators.h"
#include "util/LinkedList.h"

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

			// Map value to array initialized with a 0
			char buffer[5]; buffer[0] = 0;
			for(int i = 0; i < 4; i++)
        		buffer[i + 1] = *(((char*) &value) + i);

			ll_push(stack, buffer, 5);
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
	char buffer[5];
	ll_pop(stack, buffer);
	ll_dispose(stack);

	// Extract integer value from stack
	int result = *(int*) (buffer + 0x1);
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

	// Values are taken off stack backwards
	char val2[5];
	ll_pop(stack, val2);

	char val1[5];
	ll_pop(stack, val1);

	// Take both integer values from arrays
	int x1 = *(int*) (val1 + 0x1);
	int x2 = *(int*) (val2 + 0x1);

	// Compute answer given string operator
	int ans = evaluate_operator(op, x1, x2);

	// Map answer to new array to be pushed to stack
	char buffer[5]; buffer[0] = 0;
	for(int i = 0; i < 4; i++)
		buffer[i + 1] = *(((char*) &ans) + i);

	ll_push(stack, buffer, 5);
	return 1;

}