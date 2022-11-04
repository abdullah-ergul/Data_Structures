#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10

typedef struct{
    int data;
    struct node *next;
} node;

typedef struct{
    int cnt;
    node *top;
} stack;

void inialize(stack *);
void push(stack *, int);
int pop(stack *);


int main(){


    return 0;
}

void inialize(stack *stk){
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
