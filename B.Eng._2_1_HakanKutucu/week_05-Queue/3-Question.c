/*
    Print all elements of a Queue
*/
#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 10


typedef struct queue {
    int cnt;
    int data[QUEUE_SIZE];
    int rear, front;
} queue;

// ! Question
void printAll(queue *q){
    int i= q->front;
    while(i != q->rear){
        printf("%d\n",q->data[i]);
        i++;
        if(i == QUEUE_SIZE)
            i= 0;
    }
    printf("Done!");
}
// ! Question
