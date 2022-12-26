#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10


typedef struct priority_queue {
    int dataArr[QUEUE_SIZE + 1];
    int cnt;
} PQueue;

void initialize(PQueue *);
void swap(int *, int *);
void enqueue(PQueue *, int);
int dequeue(PQueue *);
void printHeap(PQueue *);


int main() {

    PQueue *myQueue = (PQueue *)malloc(sizeof(PQueue));
    initialize(myQueue);

    int key;
    printf("(Enter -1 for exit)\nPlease enter a Number: "); scanf("%d", &key);
    while(key != -1) {
        enqueue(myQueue, key);
        printf("Please enter a Number: "); scanf("%d", &key);
    }

    printf("\n\n");

    printHeap(myQueue);

    printf("\n\n");

    char keyC;
    printf("Do You Want to Dequeue? (y/n) : "); scanf("%c", &keyC);
    while(keyC == 'y') {
        printf("Dequeued Data: %d\n", dequeue(myQueue));
        printHeap(myQueue);
        printf("\n\nDo You Want to Dequeue? (y/n) : "); scanf("%c", &keyC);
    }

    return 0;
}

void initialize(PQueue *p) {
    p->cnt = 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void enqueue(PQueue *p, int key) {

    if(p->cnt == QUEUE_SIZE)
        printf("Queue is Full!\n");

    else {
        p->cnt++;
        p->dataArr[p->cnt] = key;

        int iter= p->cnt;
        while(iter != 0 && p->dataArr[iter] <= p->dataArr[iter/2]) {
            swap(&p->dataArr[iter], &p->dataArr[iter/2]);
            iter /= 2;
        }
    }
}

int dequeue(PQueue *p) {

    if(p->cnt == 0) {
        printf("Queue is Empty!");
        return -100;
    }

    else {
        int x= p->dataArr[1];
        p->dataArr[1] = p->dataArr[p->cnt];
        p->cnt--;

        int iter = 1;
        while(2*iter <= p->cnt && (p->dataArr[iter] > p->dataArr[2*iter] || p->dataArr[iter] > p->dataArr[2*iter+1])) {

            if(p->dataArr[iter] < p->dataArr[iter*2]) {
                swap(&p->dataArr[iter] , &p->dataArr[iter*2]);
                iter = iter*2;
            }

            else {
                swap(&p->dataArr[iter] , &p->dataArr[iter*2+1]);
                iter = iter*2+1;
            }
        }
        return x;
    }
}

void printHeap(PQueue *p) {

    if(p->cnt == 0)
        printf("Queue is Empty!\n");

    else {
        int i;
        for(i=1; i<= p->cnt; i++)
            printf("%5d", i);

        printf("\n");
        
        for(i=1; i<= p->cnt; i++)
            printf("%5d", p->dataArr[i]);
    }
}
