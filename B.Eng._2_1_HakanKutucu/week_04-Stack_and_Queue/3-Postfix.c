#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 3

typedef struct{
    char data;
    struct node *next;
} node;

typedef struct{
    int top;
    int data[STACK_SIZE];
} stack;

void reset(stack *stk);
void push(stack *, int);
int pop(stack *);
int postfix_f(char *, stack *, int);


int main(){
    char postfix[]= "32*56*+";

    return 0;
}

void reset(stack *stk){
    stk->top= -1;
}

void push(stack *stk, int c){

}

int pop(stack *stk){

}

int postfix_f(char postfix[], stack *stk, int size){
    int num1, num2, i;

    for(i=0; i<size; i++){
        if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'){
            num1= pop();
            num2= pop();
        }
    }
}
