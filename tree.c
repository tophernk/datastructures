#include <stdlib.h>
#include <stdbool.h>

typedef struct tree
{
    struct node *root;
} tree_t;

typedef struct node 
{
    struct tree *left;
    int value;
    struct tree *right;
} node_t;

void *empty();
tree_t *maketree(tree_t*,int,tree_t*);
int key(tree_t*);
tree_t *left(tree_t*);
tree_t *right(tree_t*);
bool is_empty(tree_t*);

void *empty() {
    malloc(sizeof(tree_t));
}

int main() {
    return 0;
}