#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void createQueue(queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}

int append(queueEntry e, queue *pq)
{
    queueNode *newNode = (queueNode*) malloc(sizeof(queueNode));
    if(!newNode)
        return 0;
    newNode->entry = e;
    newNode->next = NULL;
    if (!pq->rear)
        pq->front = newNode;
    else
        pq->rear->next = newNode;
    pq->rear = newNode;
    pq->size++;
    return 1;
}

void serve(queueEntry *pe, queue *pq)
{
    *pe = pq->front->entry;
    queueNode *pn = pq->front;
    pq->front = pq->front->next;
    free(pn);
    if(!pq->front)
        pq->rear = NULL;
    pq->size--;
}

int queueEmpty(queue *pq)
{
    return !pq->size;
}

int queueFull(queue *pq)
{
    return 0;
}

int queueSize(queue *pq)
{
    return pq->size;
}

void clearQueue(queue *pq)
{
    while (pq->front)
    {
        pq->rear = pq->front->next;
        free(pq->front);
        pq->front = pq->rear;
    }
    pq->size = 0;
}

void traverseQueue(queue *pq, void (*pf)(queueEntry))
{
    queueNode *pn = pq->front;
    int sz = pq->size;
    while (sz--) {
        (*pf)(pn->entry);
        pn = pn->next;
    }
}
