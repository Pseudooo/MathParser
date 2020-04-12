#include <stdio.h>

int is_number(char* str)
{
	int s = str[0] == '-' ? 1 : 0;
	int i;

	for(i = s;; i++) 
	{
		if(str[i] == 0) break;

		if(str[i] < '0' || str[i] > '9') 
		{
			return 0;
		}
	}

	if(i != s) return 1; 
	return 0;
}