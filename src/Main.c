
#include <stdio.h>
#include <string.h>

#include "Parser.h"
#include "Evaluator.h"

int main(int argc, char *argv[])
{

    if(argc != 2)
    {
        printf("Invalid Arguments!\n");
        printf("Please enter an expression to evaluate!\n");
        return 0;
    }

    char buffer[512];
    parse_infix_postfix(argv[1], buffer);

    int res;
    eval_postfix(buffer, &res);
    printf("Result: %d\n", res);

	return 0;

}