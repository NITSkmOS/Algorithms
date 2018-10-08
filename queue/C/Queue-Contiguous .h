
#ifndef C_QUEUE_CONTIGOUS_H
#define C_QUEUE_CONTIGOUS_H

#include<stdbool.h>
#include <stdio.h>
//Maximum size of the queue
#define MAXQUEUE 10

// This is an integer Queue
typedef int QueueEntry;

typedef struct queue {
    int count; // number of elements in the queue
    int front;
    int rear;
    QueueEntry entry[MAXQUEUE];
} Queue;

void createQueue(Queue *q) {
    q->count = 0;
    q->front = 0;
    q->rear = -1;
}

bool isQueueEmpty(const Queue *q) {
    return (q->count == 0);
}

bool isQueueFull(const Queue *q) {
    return (q->count == MAXQUEUE);
}

//Inserting Elements
void append(QueueEntry x, Queue *q) {
    if (isQueueFull(q))
        printf("Queue Full\n");
    else {
        q->count++;
        q->rear = (q->rear + 1) % MAXQUEUE;
        q->entry[q->rear] = x;
    }
}

//Removing Elements
void serve(QueueEntry *x, Queue *q) {
    if (isQueueEmpty(q))
        printf("cannot empty from empty queue\n");
    else {
        q->count--;
        *x = q->entry[q->front];
        q->front = (q->front + 1) % MAXQUEUE;
    }
}

int queueSize(const Queue *q) {
    return (q->count);
}

int peek(const Queue *q)
{
    int j = q->front;
    int i;

    for(i=0;i<queueSize(q);i++)
    {
        printf("%d ",q->entry[j%MAXQUEUE]);
        j++;
    }
}


#endif //C_QUEUE_CONTIGOUS_H
