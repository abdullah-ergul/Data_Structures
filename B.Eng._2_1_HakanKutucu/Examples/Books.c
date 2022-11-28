#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 10

typedef struct Book{
    int ISBN;
    char name[15];
    char authorName[15];
    int year;
} Book;

typedef struct Queue{
    int cnt;
    Book data[QUEUE_SIZE];
    int rear;
    int front;
} Queue;

void initialize(Queue *);
void enqueue(Queue *, Book);
Book dequeue(Queue *);


int main(){
    int i;
    Book b1={15,"B1","A1",2019} ,b2={23,"B2","A2",1986} ,b3={47,"B3","A3",2022} ,b4={81,"B4","A4",1914};
    Book arr[]= {b1,b2,b3,b4};
    Queue *queue= (Queue *)malloc(sizeof(Queue));
    initialize(queue);

    enqueue(queue,b1);
    enqueue(queue,b2);
    enqueue(queue,b3);
    enqueue(queue,b4);

    Book b5={3,"B5","A5",1999};
    enqueue(queue,b5);

    Book b6= dequeue(queue);
    printf("%d, %s, %s, %d",b6.ISBN,b6.name,b6.authorName,b6.year);

    return 0;
}

void initialize(Queue *q){
    q->cnt= 0;
    q->front= 0;
    q->rear= -1;
}

// ! QUESTION
void enqueue(Queue *q, Book x){
    if(q->cnt==QUEUE_SIZE)
        printf("Queue is FULL!\n");
    else{
        q->rear++;
        q->cnt++;
        if(q->rear == QUEUE_SIZE)
            q->rear= 0;
        q->data[q->rear]= x;
    }
}

Book dequeue(Queue *q){
    if(q->cnt == 0){
        printf("Queue is EMPTY!\n");
        Book a;
        return a;
    }
    else{
        Book x= q->data[q->front];
        q->front++;
        q->cnt--;
        if(q->front == QUEUE_SIZE)
            q->front= 0;
        return x;
    }
}
// ! QUESTION
