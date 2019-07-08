#include "queue.h"

Queue *queue_init() {
  Queue *q = malloc(sizeof(Queue));
  q->start = q->rear = NULL;
  return q;
}

QNode *queue_allocate_qnode(Node * node) {
  QNode *qnode = malloc(sizeof(QNode));
  qnode->node = node;
  qnode->next = NULL;
  return qnode;
}

void queue_enqueue(Queue *q, Node *node) {
  QNode *qnode = queue_allocate_qnode(node);
  if (q->rear == NULL) {
    q->start = q->rear = qnode;
  }

  q->rear->next = qnode;
  q->rear = q->rear->next;
}

Node *queue_dequeue(Queue *q) {
  if (q->start == NULL) {
    puts("Warning: Attempting to dequeue an empty queue");
    return NULL;
  }

  Node *node = NULL;
  if (q->start == q->rear) {
    QNode *qnode = q->start;
    node = qnode->node;
    q->start = q->rear = NULL;
    return node;
  }

  node = q->start->node;
  q->start = q->start->next;
  return node;
}

bool queue_empty(Queue *q) {
  return (q->start == q->rear) && (q->start == NULL);
}
