#include <stdio.h>
#include "Queue-Contiguous.h"

int main() {
    Queue myQueue;
    int temp,i;

    createQueue(&myQueue);

    printf("Is the Queue Empty? \n%s", isQueueEmpty(&myQueue) ? "true" : "false");

    append(7, &myQueue);
    append(5, &myQueue);
    append(2, &myQueue);
    append(3, &myQueue);
    append(50, &myQueue);

    printf("\nQueue Size: %d\n",queueSize(&myQueue));

    for(i = 0;i < 3; i++) {
        serve(&temp, &myQueue);
        printf("Served %d\n", temp);
    }

    peek(&myQueue);
    return 0;

}
