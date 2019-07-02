#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} node_t;

struct node *rest(node_t *list);

void print(node_t *head) {
	node_t *current = head;

	while (current != NULL) {
		printf("%d\n", current->value);
		current = rest(current);
	}
}

void *empty() {
	return malloc(sizeof(node_t));
}

struct node *rest(node_t *list) {
	if(list != NULL) {
		return list->next;
	}
	return NULL;
}

int main() {
	node_t *head = empty();
	head->value = 1;
	head->next = malloc(sizeof(node_t));
	head->next->value = 2;
	head->next->next = NULL;

	print(head);

	return 0;
}
