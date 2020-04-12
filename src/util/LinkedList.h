#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct {
	struct Node* next;
	char* str;
} Node;

typedef struct {
	struct Node* head;
	int length;
} LinkedList;

LinkedList* ll_init();

void ll_dispose(LinkedList* list);

#endif