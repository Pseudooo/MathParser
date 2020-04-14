#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
	struct Node* next;
	char* str;
} Node;

typedef struct {
	struct Node* head;
	int length;
} LinkedList;

LinkedList* ll_init();

int ll_push(LinkedList* list, char* str);
int ll_peek(LinkedList *list, char* out);
int ll_pop(LinkedList* list, char* out);
int ll_isempty(LinkedList* list);

void ll_dispose(LinkedList* list);

#endif