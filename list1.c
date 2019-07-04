#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} node_t;

struct node *rest(node_t *list);
int first(node_t *list);
struct node *append(node_t *list, int);

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

struct node *rest(node_t *list) {
	if(list != NULL) {
		return list->next;
	}
	return NULL;
}

struct node *append(node_t *list, int elem) {
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

int main() {
	node_t *list = empty();

	append(list, 1);
	append(list, 2);
	append(list, 3);

	print(list);

	print(empty());

	return 0;
}
