#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10


typedef struct {
    int top;
    int data[STACK_SIZE];
} stack;

void reset(stack *stk);
void push(stack *, int);
int pop(stack *);
void postfix_f(char *, int);


int main() {
    char postfix[] = "32*56*+";

    postfix_f(postfix, 7);

    return 0;
}

void reset(stack *stk) {
    stk->top = -1;
}

void push(stack *stk, int c) {
    if(stk->top >= STACK_SIZE-1)
        printf("Stack is Full.\n");
    else {
        stk->data[++stk->top] = c;
    }
}

int pop(stack *stk) {
    if(stk->top <= -1) {
        printf("Stack is Empty.\n");
        return -100;
    }
    else {
        return stk->data[stk->top--];
    }
}

void postfix_f(char postfix[], int size) {
    int i, x;
    stack stk; reset(&stk);

    for(i=0; i<size; i++) {

        if(postfix[i] == '+') {
            x = pop(&stk) + pop(&stk);
            push(&stk, x);
        }
        else if(postfix[i] == '-') {
            x = pop(&stk) - pop(&stk);
            push(&stk, x);
        }
        else if(postfix[i] == '*') {
            x = pop(&stk) * pop(&stk);
            push(&stk, x);
        }
        else if(postfix[i] == '/') {
            x = pop(&stk) / pop(&stk);
            push(&stk, x);
        }
        else {
            push(&stk, postfix[i] - 48);
        }
    }

    printf("%d",x);
}
