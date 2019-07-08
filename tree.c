#include "queue.h"
#include "tree.h"

void add_left_node(Node *parent, Node *left) {
  parent->left = left;
}

void add_left(Node *parent, int left) {
  Node * l = malloc(sizeof(Node));
  l->val = left;
  parent->left = l;
}

void add_right_node(Node *parent, Node *right) {
  parent->right = right;
}

void add_right(Node *parent, int right) {
  Node *r = malloc(sizeof(Node));

  r->val = right;
  parent->right = r;
}

Node *allocate_node(int val) {
  Node * node = malloc(sizeof(Node));
  node->val = val;
  node->parent = NULL;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node *dynamic_node(Node * root, Node * left, Node *right) {
  root->left = left;
  root->right = right;
  if (left != NULL)
    root->left->parent = root;
  if (right != NULL)
    root->right->parent = root;
  return root;
}

void bst_add_node(Node *root, Node *node) {
  if (root != NULL && node != NULL) {
    if (root->val > node->val) {
      if (root->left != NULL)
        root->left = node;
      else
        bst_add_node(root->left, node);
    } else {
      if (root->right != NULL)
        root->right = node;
      else
        bst_add_node(root->right, node);
    }
  }
}

void bst_add(Node *root, int val) {
  Node *node = allocate_node(val);
  bst_add_node(root, node);
}

void print_node(Node *node) {
  printf("Value is %d\n", node->val);
  if (node->left != NULL)
    print_node(node->left);
  if (node->right != NULL)
    print_node(node->right);
}

void inorder(Node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
  }
}

void preorder(Node *root) {
  if (root != NULL) {
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(Node *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
  }
}

int count_leaves(Node *root) {
  if (root->left == NULL && root->right == NULL)
    return 1;
  else
    return count_leaves(root->left) + count_leaves(root->right);
}

int count_nodes(Node *root) {
  if (root == NULL)
    return 0;
  else
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}



int find_max(Node *root) {

  if (root == NULL)
    return INT_MIN;
  int val = root->val;
  int left = find_max(root->left);
  int right = find_max(root->right);

  return max(val, max(left, right));
}

Node *find_element(Node *root, int data) {
  if (root == NULL)
    return NULL;
  if (root->val == data)
    return root;
  else {
    Node *node = NULL;
    if (root->left != NULL)
      node = find_element(root->left, data);
    if (node == NULL)
      return find_element(root->right, data);
  }
}

Node *bst_find_element(Node *root, int data) {
  if (root == NULL)
    return NULL;
  else {
    if (root->val == data)
      return root;
    else if (root->val < data)
      return bst_find_element(root->right, data);
    else
      return bst_find_element(root->left, data);
  }
}

void level_order(Node *root) {
  Queue *queue = queue_init();

  queue_enqueue(queue, root);

  while (!queue_empty(queue)) {
    Node *node = queue_dequeue(queue);
    printf("%d ", node->val);
    if (node->left != NULL)
      queue_enqueue(queue, node->left);
    if (node->right != NULL)
      queue_enqueue(queue, node->right);
  }
  puts("");
}

bool sum_exists(Node *root, int data) {
  if (root == NULL)
    return false;
  data -= root->val;

  if (data == 0) {
    if (root->left == NULL && root->right == NULL)
      return true;
    else
      return false;
  } else {
    return sum_exists(root->left, data) || sum_exists(root->right, data);
  }
}
