#include <stdio.h>

#include "Numeric.h"

int main()
{
	int result;
	printf("Is 5 a number?\n");
	result = is_number("5");
	if(result) {
		printf("yes\n");
	} else {
		printf("no\n");
	}

	printf("Is -5 a number?\n");
	result = is_number("-5");
	if(result) {
		printf("yes\n");
	} else {
		printf("no\n");
	}

	printf("Is - a number?\n");
	result = is_number("-");
	if(result) {
		printf("yes\n");
	} else {
		printf("no\n");
	}

	printf("Is 0 a number?\n");
	result = is_number("0");
	if(result) {
		printf("yes\n");
	} else {
		printf("no\n");
	}

	printf("Is s a number?\n");
	result = is_number("s");
	if(result) {
		printf("yes\n");
	} else {
		printf("no\n");
	}

	return 1;
}