#include "utils.h"

#ifndef TREE_H
#define TREE_H

typedef struct Node {
  int val;
  struct Node *left;
  struct Node *right;
  struct Node *parent;
} Node;

void add_left_node(Node *, Node *);
void add_left(Node *, int);
void add_right_node(Node *, Node *);
void add_right(Node *, int);
Node *allocate_node(int);
Node *dynamic_node(Node *, Node *, Node *);

void bst_add_node(Node *, Node *);
void bst_add(Node *, int);

void print_node(Node *);

void inorder(Node *);
void preorder(Node *);
void postorder(Node *);
void level_order(Node *);

int count_leaves(Node *);
int count_nodes(Node *);
int count_parents(Node *);
int find_max(Node *);

Node *find_element(Node *, int);
Node *bst_find_element(Node *, int);

bool sum_exists(Node *, int);

#endif
