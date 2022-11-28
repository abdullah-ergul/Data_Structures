#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10
#define QUEUE_SIZE 10

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct{
    int cnt;
    node *top;
} stack;

typedef struct{
    int cnt;
    node *front;
    node *rear;
} queue;

void stackInialize(stack *);
void push(stack *, int);
int pop(stack *);
void queueInialize(queue *);
void enqueue(queue *, int);
int dequeue(queue *);

void swapStackAndQueue(queue *, stack *);


int main(){
    return 0;
}

void swapStackAndQueue(queue *q, stack *s){
    stack *tempStack;
    stackInialize(tempStack);

    while(s->cnt != 0)
        push(tempStack, pop(s));

    while(q->cnt != 0)
        push(s, dequeue(q));

    while(tempStack->cnt != 0)
        enqueue(q, pop(tempStack));
}

void stackInialize(stack *stk){
    stk->cnt= 0;
    stk->top= NULL;
}

void push(stack *stk, int c){
    if(stk->cnt >= STACK_SIZE)
        printf("Stack is Full.\n");
    else{
        node *temp= (node *)malloc(sizeof(node));
        temp->data= c;
        temp->next= stk->top;
        stk->top= temp;
        stk->cnt++;
    }
}

int pop(stack *stk){
    if(stk->cnt <= 0){
        printf("Stack is Empty.\n");
        return -100;
    }
    else{
        int x= stk->top->data;
        node *temp= (node *)malloc(sizeof(node));
        stk->top= stk->top->next;
        free(temp);
        stk->cnt--;
        return x;
    }
}

void queueInialize(queue *q){
    q->cnt= 0;
    q->front = q->rear = NULL;
}

void enqueue(queue *q, int x){
    if(q->cnt == QUEUE_SIZE)
        printf("Queue is FULL");
    else{
        node *temp= (node *)malloc(sizeof(node));
        temp->data= x; temp->data= NULL;

        if(q->cnt == 0)
            q->front= q->rear= temp;
        else{
            q->rear->next= temp;
            q->rear= temp; 
        }
        q->cnt++;
    }
}

int dequeue(queue *q){
    if(q->cnt == 0){
        printf("Queue is EMPTY");
        return -100;
    }
    else{
        int x= q->front->data;
        node *temp= q->front;
        q->front= q->front->next;
        free(temp);
        q->cnt--;
        return x;
    }
}
