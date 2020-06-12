
#include "Parser.h"
#include "util/Numeric.h"
#include "util/Operators.h"

#include <stdio.h>

void buffer_tolist(char* buffer, LinkedList* dest);
void buffer_extend(char* buffer, char c);

/*
    Parse a provided expression from infix to postfix
    which can then be evaluated by the evaluator
*/
int parse_infix(char* expr, char* dest)
{

    // ...

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
        else if(is_operator(buffer))
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
