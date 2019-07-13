#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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
    return malloc(sizeof(tree_t));
}

tree_t *maketree(tree_t *l,int v, tree_t *r) {
    tree_t *t = empty();
    node_t *n = malloc(sizeof(node_t));
    n->left=l;
    n->right=r;
    n->value=v;
    t->root=n;
}

void print_tree(tree_t *t) {
    if(t->root != NULL) {
        printf("%d\n", t->root->value);
        print_tree(t->root->left);
        print_tree(t->root->right);
    }
}

int main() {
    tree_t *l = maketree(empty(), 1, empty());
    tree_t *r = maketree(empty(), 2, empty());
    tree_t *t = maketree(l, 0, r);
    print_tree(t);

    return 0;
}