#include<stdio.h>

// Queue structure
struct queue {
    int arr[10];
    int front, end;
};

// Initialize the queue
void init(struct queue *st) {
    st->front = 0;
    st->end = 0;
}

// Method to check if the queue st is full or empty
void check(struct queue *st) {
    if (st->front == 0 && st->end == 0)
        printf("The queue is empty!!!!\n");
    else if (st->end==10)
        printf("The queue is full!!!!\n");
}

// Method to insert elements in the queue st
void enqueue(struct queue *st, int ele) {
    check(st);
    st->arr[(st->end)++] = ele;
}

// Method to remove first element from the queue st
int dequeue(struct queue *st) {
    check(st);
    return st->arr[(st->front)++];
}

// Method to show elements in the queue st
void show(struct queue st) {
    for (int i = st.front; i < st.end; i++)
        printf("%d", st.arr[i]);
}

// Driver method
void main() {
    struct queue st;
    init(&st);
    for (int i = 1; i < 9; i++)
        enqueue(&st, i);
    show(st);
    putchar('\n');
    printf("%d\n", dequeue(&st));
    enqueue(&st, 6);
    show(st);
    putchar('\n');
    enqueue(&st, 9);
    show(st);
    putchar('\n');
    printf("%d\n", dequeue(&st));
    printf("%d\n", dequeue(&st));
    printf("%d\n", dequeue(&st));

    putchar('\n');
}
