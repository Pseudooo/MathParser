
#include <stdlib.h>
#include <sting.h>

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

	// Return pointer
	return list;

}

/**
	Will push the string provided to the front of the list
	1 -> Push successful
	0 -> Failed to allocate memory
*/
int ll_push(LinkedList* list, char* str)
{

	// Calculate length of string
	int len = 0;
	for(;;len++)
		if(str[len] == 0) break;

	// Attempt allocation of data
	Node* node = malloc(sizeof(Node));
	char* node_str = malloc(len);
	if(node == NULL || str == NULL)
		return 0; // Failed to allocate

	// Copy provided string into the node
	node->str = node_str;
	for(int i = 0; i < len; i++)
		node_str[i] = str[i];

	// Link node into front of list
	node->next = list->head;
	list->head = node;

	list->length++;
	return 1;

}

/**
	Will remove the first element of the list and place its data in the
	provided location
	1 - Successful
	0 - Empty List Error
*/
int ll_pop(LinkedList* list, char* out)
{

	// Catch edge-case
	if(list->length == 0)
		return 0;

	// Unlink head from list
	Node* to_des = list->head;
	list->head = to_des->next;

	list->length--;
	strcpy(out, to_des->str);

	// Clear from memory
	free(to_des->str);
	free(to_des);

	return 1;

}

void ll_dispose(LinkedList* list)
{

	// ...

}