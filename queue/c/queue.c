#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    struct queue *next;
    int value;
} Queue;

/* Makes a single element of a queue */
Queue* make_queue_element(int value) {
    Queue* new_elem = (Queue*) malloc (sizeof(Queue));
    
    new_elem->value = value;
    new_elem->next = NULL;

    return new_elem;
}

/* Checks if the queue is empty */
int is_empty(Queue* q) {
    if(q == NULL)
        return 1;
    else
        return 0;
}

/* Adds element at the end of a queue */
Queue* enqueue(Queue* q, int new_value)
{
     Queue* i;
     
     if(is_empty(q) == 1) {
         return make_queue_element(new_value);
     }

     for(i = q; i->next != NULL; i = i->next)
     {}

     i->next = make_queue_element(new_value);

     return q;
}

/* Remove first element in the queue */
Queue* dequeue(Queue* q)
{
    Queue* new_q;
    Queue* aux;
    if(is_empty(q) == 1)
        return NULL;
    else
    {
        new_q = aux = q;
        new_q = new_q->next;
        aux->next = NULL;
        free(aux);
        return new_q;
    }
}

/* Prints the queue */
void list(Queue* q)
{
    Queue* i;

    if (is_empty(q) == 1)
    {
         printf("Queue empty!\n");
        return;
    }
    else
    {
        for(i = q; i != NULL; i = i->next)
        {
            printf("%d ", i->value);
        }
        printf("\n");
    }

}

int main(void)
{
    Queue* q = NULL;
    int choice;
    int value;

    while(1) {
        printf("1: Enqueue; 2: Dequeue; 3: List; 4: Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("your value: ");
                scanf("%d", &value);
                q = enqueue(q, value);
                break;
            case 2:
                q = dequeue(q);
                break;
            case 3:
                list(q);
                break;
            case 4:
                return 0;
        }
    }
    return 0;
}
