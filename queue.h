#include "utils.h"
#include "tree.h"

#ifndef QUEUE_H
#define QUEUE_H

typedef struct QNode{
  Node *node;
  struct QNode *next;
} QNode;

typedef struct {
  QNode *start;
  QNode *rear;
} Queue;

Queue *queue_init();
QNode *queue_allocate_qnode(Node *);
void queue_enqueue(Queue *, Node *);
Node *queue_dequeue(Queue *);
bool queue_empty(Queue *);

#endif
