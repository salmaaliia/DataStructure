/*Circular Implementation*/

#include "queue.h"

void createQueue(queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void append(queueEntry e, queue *pq)
{
    pq->rear = (pq->rear + 1) % MAXQUEUE;
    pq->entry[pq->rear] = e;
    pq->size++;
}

void serve(queueEntry *pe, queue *pq)
{
    *pe = pq->entry[pq->front];
    pq->front = (pq->front + 1) % MAXQUEUE;
    pq->size--;
}

int queueEmpty(queue *pq)
{
    return !pq->size;
}

int queueFull(queue *pq)
{
    return (pq->size == MAXQUEUE);
}

int queueSize(queue *pq)
{
    return pq->size;
}

int clearQueue(queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void traverseQueue(queue *pq, void (*pf)(queueEntry))
{
    int pos, s;
    for(pos = pq->front, s = 0; s < pq->size; s++)
    {
        (*pf)(pq->entry[pos]);
        pos = (pos + 1) % MAXQUEUE;
    }
}




