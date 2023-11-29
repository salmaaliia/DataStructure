#ifndef QUEUE_H_
#define QUEUE_H_


#define queueEntry int
#define MAXQUEUE 100

typedef struct Queue{
    int front;
    int rear;
    int size;
    queueEntry entry[MAXQUEUE];
}queue;

void createQueue(queue*);

void append(queueEntry, queue*);

void serve(queueEntry*, queue*);

int queueEmpty(queue*);

int queueFull(queue*);

int queueSize(queue*);

int clearQueue(queue*);

void traverseQueue(queue *, void (*)(queueEntry));

#endif