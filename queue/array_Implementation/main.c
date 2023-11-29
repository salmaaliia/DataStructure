#include <stdio.h>
#include "queue.h"
void display(queueEntry);
int main() {
    queue q;
    queueEntry e;
    queueEntry *pe;
    createQueue(&q);
    if(!queueFull(&q))
    {
        e = 5;
        append(e, &q);
    }
    if(!queueFull(&q))
    {
        e = 7;
        append(e, &q);
    }
    traverseQueue(&q, display);
    printf("Queue size: %d\n", queueSize(&q));
    if(!queueEmpty(&q))
    {
        serve(&e, &q);
    }
    traverseQueue(&q, display);
    printf("Queue size: %d\n", queueSize(&q));
    clearQueue(&q);
    printf("Queue size: %d\n", queueSize(&q));

    return 0;
}

void display(queueEntry e)
{
    printf("%d\n", e);
}
