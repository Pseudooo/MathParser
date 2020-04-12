
#include <stdlib.h>

#include "LinkedList.h"

/**
	Will initialize a linked list in the heap and return its pointer
	will return a null pointer if the malloc operation fails
*/
LinkedList* ll_init()
{

	// Attempt the allocation of the list
	LinkedList* list = malloc(sizeof(LinkedList));
	if(list == NULL)
		return NULL;

	// Assign 
	list->head = NULL;
	list->length = 0;

	return list;

}

void ll_dispose(LinkedList* list)
{

	// ...

}