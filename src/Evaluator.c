
#include <string.h>
#include <stdio.h>

#include "Evaluator.h"

#include "util/Numeric.h"
#include "util/Operators.h"
#include "util/LinkedList.h"

int perform_operation(LinkedList* stack, char* op);

int eval_postfix(const char* postfix_expr, int* dest)
{

	LinkedList* stack = ll_init();

	// Make a local copy of the expression to tokenize
	char str[strlen(postfix_expr) + 1];
	strcpy(str, postfix_expr);

	char* token = strtok(str, " ");
	while(token != NULL)
	{
		if(is_integer(token))
		{
			int value = from_str(token);

			// Map value to array initialized with a 0
			char buffer[5]; buffer[0] = 0;
			for(int i = 0; i < 4; i++)
        		buffer[i + 1] = *(((char*) &value) + i);

			ll_push(stack, buffer, 5);
		}
		else if(is_operator(token))
		{
			// Operators are performed on the stack
			perform_operation(stack, token);
		}
		else
		{	
			// Invalid Token encountered
			return 0;
		}

		token = strtok(NULL, " ");
	}

	if(stack->length != 1)
		return 0;

	char buffer[5];
	ll_pop(stack, buffer);
	ll_dispose(stack);

	int result = *(int*) (buffer + 0x1);
	*dest = result;
	return 1;

}

int perform_operation(LinkedList* stack, char* op)
{

	// printf("Performing operation: %s\n", op);

	// Values are taken off stack backwards
	char val2[ll_peek_size(stack)];
	ll_pop(stack, val2);

	char val1[ll_peek_size(stack)];
	ll_pop(stack, val1);

	// printf("Arr1: ");
	// for(int i = 0; i < 5; i++)
	// 	printf("%02X ", val1[i]);
	// printf("\n\n");

	// printf("Arr2: ");
	// for(int i = 0; i < 5; i++)
	// 	printf("%02X ", val2[i]);
	// printf("\n");

	// Ensure both values are integer values
	if(val1[0] == 1 || val2[0] == 1)
		return 0; // Invalid stack

	int x1 = *(int*) (val1 + 0x1);
	int x2 = *(int*) (val2 + 0x1);
	int ans = evaluate_operator(op, x1, x2);

	// printf("x1 = %d\nx2 = %d\nanswer = %d\n", x1, x2, ans);

	char buffer[5]; buffer[0] = 0;
	for(int i = 0; i < 4; i++)
		buffer[i + 1] = *(((char*) &ans) + i);

	ll_push(stack, buffer, 5);
	return 1;

}