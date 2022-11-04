#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 3

typedef struct{
    int data;
    struct node *next;
} node;

typedef struct{
    int top;
    int data[STACK_SIZE];
} stack;

void reset(stack *);
void push(stack *, int);
int pop(stack *);


int main(){


    return 0;
}

void reset(stack *stk){
    stk->top= -1;
}

void push(stack *stk, int c){
    if(stk->top >= STACK_SIZE-1)
        printf("Stack is Full.\n");
    else{
        // stk->top++;
        // stk->data[stk->top]= c;
        stk->data[++stk->top]= c;
    }
}

int pop(stack *stk){
    if(stk->top <= -1){
        printf("Stack is Empty.\n");
        return -100;
    }
    else{
        // int x= stk->data[stk->top];
        // stk->top--;
        // return x;
        return stk->data[--stk->top];
    }
}
