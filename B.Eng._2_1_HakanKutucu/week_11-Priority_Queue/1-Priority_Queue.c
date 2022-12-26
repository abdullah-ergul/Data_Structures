#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10


typedef struct priority_queue {
    int dataArr[QUEUE_SIZE + 1];
    int cnt;
} PQueue;

void initialize(PQueue *);
void insert(PQueue *, int);
void printHeap(PQueue *);


int main() {
    PQueue *myQueue = (PQueue *)malloc(sizeof(PQueue));
    initialize(myQueue);

    int key;
    
    printf("(Enter -1 for exit)\nPlease enter a Number: "); scanf("%d", &key);
    while(key != -1) {
        insert(myQueue, key);
        printf("\n(Enter -1 for exit)\nPlease enter a Number: "); scanf("%d", &key);
    }

    printHeap(myQueue);

    return 0;
}

void initialize(PQueue *p) {
    p->cnt = 0;
}

void insert(PQueue *p, int key) {
    if(p->cnt == QUEUE_SIZE)
        printf("Queue is Full!\n");

    else {
        p->cnt++;
        p->dataArr[p->cnt] = key;

        int iter= p->cnt;
        while(iter != 0 && p->dataArr[iter] <= p->dataArr[iter/2]) {
            int temp = p->dataArr[iter];
            p->dataArr[iter] = p->dataArr[iter/2];
            p->dataArr[iter/2] = temp;
            iter /= 2;
        }
    }
}

void printHeap(PQueue *p) {
    printf("\n\n");

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
