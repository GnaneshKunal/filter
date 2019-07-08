#include "tree.h"
#include "hash.h"
#include "bloom.h"

int main(void) {

  srand(time(NULL));

  const unsigned int SEED = rand();
  const unsigned int BUCKET_SIZE = 30;

  const char *names[] = {"gnanesh", "shubham", "himani", "sahana", "nishant", "arushi"};

  Bloom *bloom = bloom_init(BUCKET_SIZE);

  for (int i = 0; i < 6; i++) {
    bloom_add(bloom, (const void *)names[i], strlen(names[i]), SEED);
  }

  printf("%s %d\n", names[0], bloom_check(bloom, names[0], strlen(names[0]), SEED));
  char *name = "Gnanesh";
  printf("%s %d\n", name, bloom_check(bloom, name, strlen(name), SEED));

  Node *root = allocate_node(1);
  root->left = allocate_node(2);
  root->right = allocate_node(3);

  root->left->left = allocate_node(4);
  root->left->right = allocate_node(5);

  inorder(root), puts("");

  preorder(root), puts("");

  postorder(root), puts("");

  printf("Count leaves %d\n", count_leaves(root));

  printf("Count nodes %d\n", count_nodes(root));

  printf("Find max %d\n", find_max(root));

  Node *search_node = find_element(root, 2);

  printf("Find element %d\n", search_node ? search_node->val : -1);

  level_order(root);

  printf("Sum exists %d %s\n", 7, sum_exists(root, 7) ? "true" : "false");

  root = dynamic_node(allocate_node(2),
                      dynamic_node(allocate_node(7),
                                   dynamic_node(allocate_node(2),
                                                NULL,
                                                NULL),
                                   dynamic_node(allocate_node(6),
                                                dynamic_node(allocate_node(5),
                                                             NULL,
                                                             NULL),
                                                dynamic_node(allocate_node(11),
                                                             NULL,
                                                             NULL)
                                                )
                                   ),
                      dynamic_node(allocate_node(5),
                                   NULL,
                                   dynamic_node(allocate_node(9),
                                                dynamic_node(allocate_node(4),
                                                             NULL,
                                                             NULL),
                                                NULL)
                                   )
                      );

  inorder(root), puts("");

  preorder(root), puts("");

  postorder(root), puts("");

  return 0;
}
