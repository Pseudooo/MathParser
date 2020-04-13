#include <stdio.h>

#include "Numeric.h"

int main()
{
	printf("-----------------------------------");
	/** is_number testing */
	int result;
	printf("\nTesting is_number\n\n");
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

	printf("Is '' a number?\n");
	result = is_number("");
	if(result) {
		printf("yes\n");
	} else {
		printf("no\n");
	}

	printf("-----------------------------------");
	/** from_str testing */
	printf("\n\nTesting from_str\n\n");
	printf("1 - Success\n0 - Invalid Number\n-1 - Empty String\n\n");
	int dest;
	printf("20 => %d\n", from_str("20", &dest));
	printf("-5 => %d\n", from_str("-5", &dest));
	printf("asdf => %d\n", from_str("asdf", &dest));
	printf("\"\" => %d\n", from_str("", &dest));
	printf("- => %d\n", from_str("-", &dest));

	/** to_str testing */
	printf("\n\nTesting to_str\n\n");
	for(int i = -8; i < 8; i++)
	{
		int val = i*i*i;
		printf("Converting %d to string\n", val);
		char str[32];
		to_str(val, str);
		printf("String: %s\n", str);

	}

	return 1;
}