#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 10


typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct queue {
    int cnt;
    node *front;
    node *rear;
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
    q->front = q->rear = NULL;
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
        node *temp = (node *)malloc(sizeof(node));
        temp->data = x;  temp->next = NULL;

        if (isEmpty(q))
            q->front = q->rear = temp;

        else {
            q->rear->next = temp;
            q->rear = temp;
        }

        q->cnt++;
    }

}

int dequeue(queue *q) {
    int x;

    if (isEmpty(q)) {
        printf("Queue is Empty!");
        x = -100;
    }

    else {
        int x = q->front->data;
        node *temp = q->front;
        q->front = q->front->next;
        free(temp);
        q->cnt--;
    }

    return x;
}
 