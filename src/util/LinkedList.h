#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
	struct Node* next;
	size_t alloc;
	void* payload;
} Node;

typedef struct {
	struct Node* head;
	struct Node* tail;
	int length;
} LinkedList;

LinkedList* ll_init();

int ll_push(LinkedList* list, void* src, size_t n);
int ll_pop(LinkedList* list, void* dest);

int ll_peek(LinkedList *list, void* dest);
int ll_peek_size(LinkedList* list);

int ll_append(LinkedList* list, void* src, size_t n);

int ll_isempty(LinkedList* list);
void ll_dispose(LinkedList* list);

#endif