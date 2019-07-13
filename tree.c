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

int key(tree_t *t) {
    return t->root->value;
}

tree_t *left(tree_t *t) {
    return t->root->left;
}

tree_t *right(tree_t *t) {
    return t->root->right;
}

bool is_empty(tree_t *t) {
    return t->root == NULL;
}

void print_tree(tree_t *t) {
    if(t->root != NULL) {
        printf("%d\n", key(t));
        print_tree(left(t));
        print_tree(right(t));
    }
}

int main() {
    tree_t *l = maketree(empty(), 1, empty());
    tree_t *r = maketree(empty(), 2, empty());
    tree_t *t = maketree(l, 0, r);
    print_tree(t);

    printf("%s\n", is_empty(t) ? "true" : "false");
    printf("%s\n", is_empty(empty()) ? "true" : "false");

    return 0;
}