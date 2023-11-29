#ifndef QUEUE_H_
#define QUEUE_H_

#define queueEntry int

typedef struct QueueNode{
    queueEntry entry;
    struct QueueNode *next;
}queueNode;

typedef struct Queue{
    queueNode *front;
    queueNode *rear;
    int size;
}queue;

void createQueue(queue*);

int serve(queueEntry*, queue*);

int queueEmpty(queue*);

int queueFull(queue*);

int queueSize(queue*);

void traverseQueue(queue*, void (*)(queueEntry));

#endif