#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 10


typedef struct queue {
    int cnt;
    int data[QUEUE_SIZE];
    int rear, front;
} queue;

void initialize(queue *);
int isFull(queue *);
int isEmpty(queue *);
void enqueue(queue *, int);
int dequeue(queue *);


int main() {


    return 0;
}

void initialize(queue *q) {
    q->cnt = 0;
    q->front = 0;
    q->cnt = -1;
}

int isFull(queue *q) {

    if (q->cnt == QUEUE_SIZE)
        return 1;

    else
        return 0;

}

int isEmpty(queue *q) {

    if (q->cnt == 0)
        return 1;

    else
        return 0;

}

void enqueue(queue *q, int x) {

    if (isFull(q))
        printf("Queue is Full!");

    else {
        q->rear++;
        q->cnt++;
        if (q->rear == QUEUE_SIZE)
            q->rear = 0;
        q->data[q->rear] = x;
    }

}

int dequeue(queue *q) {
    int x;

    if (isEmpty(q)) {
        printf("Queue is Empty!");
        x = -100;
    }
    
    else {
        x = q->data[q->front];
        q->front++;
        q->cnt--;

        if (q->front == QUEUE_SIZE)
            q->front = 0;
    }

    return x;
}
