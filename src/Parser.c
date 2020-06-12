
#include "Parser.h"
#include "util/Numeric.h"
#include "util/Operators.h"

#include <stdio.h>

void buffer_tolist(char* buffer, LinkedList* dest);
void buffer_extend(char* buffer, char c);

/*
    Parse a provided expression from infix to postfix
    which can then be evaluated by the evaluator
        TODO:
            - refactor code heavily
            - make robust to catch invalid expressions
*/
int parse_infix_postfix(char* expr, char* dest)
{

    LinkedList* tokens = ll_init();
    tokenize(expr, tokens);

    LinkedList* postfix_ll = ll_init();
    LinkedList* stack = ll_init();

    while(!ll_isempty(tokens))
    {

        // Take token from list
        const int n = ll_peek_size(tokens);
        char tok[n];
        ll_pop(tokens, tok);

        printf("Processing token: %s\n", tok);

        if(is_integer(tok))
        {
            // Operands are added to expression
            ll_append(postfix_ll, tok, n);
        }
        else if(tok[0] == '(')
        {
            // Opening brackets are added to stack
            ll_push(stack, tok, n);
        }
        else if(is_operator(tok))
        {
            // Operators we check pop all operators of higher
            // or equal precedence to the expression

            // Take precedence of current operator
            const int cur_prec = operator_prec(tok);

            char buffer[256];
            for(int i = 0; i < 256; i++)
                buffer[i] = 0;

            // Pop stack of all operators that are higher prec
            while(!ll_isempty(stack) && operator_prec(stack->head->payload) >= cur_prec)
            {
                // Pop operator from stack onto expression
                const int size = ll_peek_size(stack);
                ll_pop(stack, buffer);
                ll_append(postfix_ll, buffer, size);
            }

            // Add operator to stack
            ll_push(stack, tok, n);

        }
        else if(tok[0] == ')')
        {
            // Closing brackets require us to pop all stack
            // elements until opening bracket is met

            char buffer[256];
            for(int i = 0; i < 256; i++)
                buffer[i] = 0;

            while(buffer[0] != '(')
            {
                const int size = ll_peek_size(stack);
                ll_pop(stack, buffer);

                if(buffer[0] != '(')
                    ll_append(postfix_ll, buffer, size);
            }

        }

    }

    ll_dispose(stack);
    ll_dispose(tokens);

    /*
        Now the postfix expression exits with each term
        being its own element within `postfix_ll` so we
        are now going to convert this to be its own string

        
    */

    char buffer[256];
    for(int i = 0; i < 256; i++)
        buffer[i] = 0;

    int head = 0;
    while(!ll_isempty(postfix_ll))
    {

        ll_peek(postfix_ll, buffer);
        const int size = ll_peek_size(postfix_ll) - 1;
        
        ll_pop(postfix_ll, dest + head);

        head += size;

        if(postfix_ll->length >= 1)   
            dest[head++] = ' ';

    }

    ll_dispose(postfix_ll);

    return 1;

}

/*
    Helper function that will convert the potentially "messy"
    input string into a nice iterable list of characters
*/
void tokenize(const char* str, LinkedList* dest)
{

    // Create a buffer to contain the 
    char buffer[256];
    for(int i = 0; i < 256; i++)
        buffer[i] = 0;

    int idx = 0;
    while(str[idx] != 0)
    {

        // Skipping white space
        if(str[idx] == ' ')
        {
            idx++;
            continue;
        }

        if(is_integer(buffer) && !is_digit(str[idx]))
        {
            buffer_tolist(buffer, dest);
        }
        else if(is_operator(buffer) || buffer[0] == '(' || buffer[0] == ')')
        {
            buffer_tolist(buffer, dest);
        }

        buffer_extend(buffer, str[idx++]);

    }

    // Remaining contents of the buffer 
    // are assumed to be final token
    buffer_tolist(buffer, dest);

}

/*
    Helper function to dump the contents of the buffer to the
    list and clear it
*/
void buffer_tolist(char* buffer, LinkedList* dest)
{
    // Append buffer to the list
    int len = 0;
    while(buffer[len] != 0) len++;
    ll_append(dest, buffer, ++len);

    // Clear buffer for new data
    int idx = 0;
    while(buffer[idx] != 0)
        buffer[idx++] = 0;
}

/*
    Helper function to add a new character to
    the buffer
*/
void buffer_extend(char* buffer, char c)
{
    int idx = 0;
    for(;;idx++)
        if(buffer[idx] == 0)
        {
            buffer[idx] = c;
            break;
        }
}
