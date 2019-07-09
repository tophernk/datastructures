#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} node_t;

struct node *rest(node_t*);
int first(node_t*);
struct node *append(node_t *, int);
struct node *concat(node_t *, node_t*);

void print(node_t *head) {
	if(head->next == NULL) {
		return;
	}
	node_t *current = head->next;

	while (current != NULL) {
		printf("%d\n", first(current));
		current = rest(current);
	}
}

void *empty() {
	return malloc(sizeof(node_t));
}

int first(node_t *list) {
	if(list != NULL) {
		return list->value;
	}
	return -1;
}

struct node *last(node_t *list) {
	if(list == NULL) {
		return list;
	}
	node_t *current = list;
	while(current->next != NULL) {
		current = rest(current);
	}
	return current;
}

struct node *rest(node_t *list) {
	if(list != NULL) {
		return list->next;
	}
	return NULL;
}

struct node *append(node_t *list, int elem) {
	if(list == NULL) {
		list = empty();
	}
	node_t *current = list;

	while(current->next != NULL) {
		current = rest(current);
	}

	node_t *next_elem = malloc(sizeof(node_t));
	next_elem->value = elem;
	next_elem->next = NULL;

	current->next = next_elem;

	return list;
}

struct node *concat(node_t *a, node_t *b) {
	if(a == NULL) {
		a = empty();
	}
	if(b == NULL) {
		b = empty();
	}
	last(a)->next=b->next;
	return a;
}

int main() {
	node_t *a = empty();

	for(int i=0; i<20; i++) {
		append(a, i);
	}

	node_t *b = empty();
	for(int i=20; i<40; i++) {
		append(b, i);
	}

	print(concat(a, b));


	return 0;
}
