#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} node_t;

void print(node_t *head) {
	node_t *current = head;

	while (current != NULL) {
		printf("%d\n", current->value);
		current = current->next;
	}
}

int main() {
	node_t *head = NULL;
	head = malloc(sizeof(node_t));
	head->value = 1;
	head->next = malloc(sizeof(node_t));
	head->next->value = 2;
	head->next->next = NULL;

	print(head);

	return 0;
}