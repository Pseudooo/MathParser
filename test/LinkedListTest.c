
#include <stdio.h>

#include "../src/util/LinkedList.h"

int main()
{

	// ************ LIST  INITIALIZATION
	printf(" *** Initializing List\n");
	LinkedList* list = ll_init();
	if(list == NULL)
	{
		printf("Failed to allocate!\n");
		return 1;
	}
	else printf("Done!\n");

	printf("ll_isempty() => %d\n", ll_isempty(list));

	char out[256];

	// ************ PUSHING VALUES
	char* arr[] = {"one", "two", "three", "four", "five"};
	for(int i = 0; i < 5; i++)
	{
		char* str = arr[i];

		// Attempt push of value
		printf("Attempting to push: %s\n", str);
		ll_push(list, str);

		// Output new head
		ll_peek(list, out);
		printf("Updated Head is: %s\n\n", out);

	}

	printf("ll_isempty() => %d\n", ll_isempty(list));

	// Padding
	printf("\n");


	// ************ DISPLAYING CURRENT LIST
	printf("Current List is:\n");
	Node* cur = list->head;
	while(cur != NULL)
	{
		printf("%s", cur->str);
		if(cur->next != NULL)
		{
			printf(" -> ");
		}
		else printf("\n\n");
		cur = cur->next;
	}

	// ************ POPPING VALUES
	printf("Popping all values...\n");
	while(list->length > 0)
	{
		ll_pop(list, out);
		printf("Popped: %s\n", out);
	}

	printf("ll_isempty() => %d\n", ll_isempty(list));

	return 1;

}
