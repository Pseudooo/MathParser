
#include <stdlib.h>
#include <string.h>

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
	list->tail = NULL;
	list->length = 0;

	// Return pointer
	return list;

}

/**
	Will push the string provided to the front of the list
	1 -> Push successful
	0 -> Failed to allocate memory
   -1 -> Null Pointer(s) given
*/
int ll_push(LinkedList* list, void* src, size_t n)
{

	if(list == NULL || src == NULL)
		return -1;

	// Attempt to allocate resources
	Node* node = malloc(sizeof(Node));
	void* payload = calloc(1, n);
	if(node == NULL || payload == NULL)
	{
		// Other resource potentially successful alloc
		if(node != NULL)free(node);
		if(payload != NULL) free(payload);
		return 0;
	}

	// Populate node
	node->alloc = n;
	node->payload = payload;
	memcpy(payload, src, n);

	// Link node to head
	node->next = list->head;
	list->head = node;

	// If list is empty link to tail
	if(list->length == 0)
		list->tail = node;

	list->length++;
	return 1;

}

/**
	Will remove the first element of the list and place its data in the
	provided location
	1 - Successful
	0 - Empty List Error
*/
int ll_pop(LinkedList* list, void* dest)
{

	if(list == NULL || list->length == 0)
		return 0;

	// Unlink head from list
	Node* to_des = list->head;
	list->head = to_des->next;

	list->length--;

	// (Optionally) copy to dest
	if(dest != NULL)
		memcpy(dest, to_des->payload, to_des->alloc);

	// Clear from memory
	free(to_des->payload);
	free(to_des);

	if(list->length == 0)
		list->tail = NULL;

	return 1;

}

/**
	Will let the user view the string at the head
	1 - Success
	0 - Empty List
   -1 - Null Pointer given
*/
int ll_peek(LinkedList* list, void* dest)
{
	
	// Catch edge-case
	if(list->length == 0)
		return 0;

	if(dest == NULL)
		return -1;

	Node* head = list->head;
	memcpy(dest, head->payload, head->alloc);
	return 1;

}

/**
	Will return the size of the first node of the given list
	-1 - Null Pointer given or empty list
*/
int ll_peek_size(LinkedList* list)
{
	if(list == NULL || list->length == 0)
		return -1;

	return list->head->alloc;
}

/**
	Will append a node to the end of the list
	1 - Success
	0 - Memory Allocation failed
   -1 - Invalid List given	
*/
int ll_append(LinkedList* list, void* src, size_t n)
{
	
	if(list == NULL || src == NULL)
		return -1;

	// Attempt allocation of resources
	Node* node = malloc(sizeof(Node));
	void* payload = calloc(1, n);
	if(node == NULL || payload == NULL)
	{
		// Free appropriate 
		if(node != NULL) free(node);
		if(payload != NULL) free(node);
		return 0;
	}

	// Populate node
	node->payload = payload;
	node->alloc = n;
	memcpy(payload, src, n);

	// Link node into list
	if(list -> length == 0)
		list->head = node;
	else 
		list->tail->next = node;
	list->tail = node;

	list->length++;
	return 1;

}

/**
	Will determine if the provided list is empty or not
*/
int ll_isempty(LinkedList* list)
{
	return list->length == 0;
}

void ll_dispose(LinkedList* list)
{

	// Popping elements frees them from memory
	while(list->length > 0)
		ll_pop(list, NULL);

	// Free list
	free(list);

}