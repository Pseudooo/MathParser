
#include <stdio.h>

#include "LinkedList.h"

int main()
{

	printf("Initializing list\n");
	LinkedList* list = ll_init();
	if(list == NULL)
	{
		printf("Failed to allocate!\n");
		return 1;
	}
	else printf("Done!\n");

	char out[256];

	printf("Pushing \"one\"\n");
	ll_push(list, "one"); ll_peek(list, out);
	printf("New Head: %s\n", out);

	printf("Pushing \"two\"\n");
	ll_push(list, "two"); ll_peek(list, out);
	printf("New Head: %s\n", out);

	printf("Pushing \"tre\"\n");
	ll_push(list, "tre"); ll_peek(list, out);
	printf("New Head: %s\n", out);

	printf("Popping all values...\n");
	while(list->length > 0)
	{
		ll_pop(list, out);
		printf("Popped: %s\n", out);
	}

	return 1;

}
