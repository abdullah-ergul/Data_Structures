#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

void addDLL(node *, int);
void combine(node *, node *);


int main(){
    

    return 0;
}

void addDLL(node *head, int x){
    node *p= head;
    node *temp= (node *)malloc(sizeof(node));
    temp->data= x;

    while(p->next != head)
        p= p->next;
    p->next= temp;
    temp->next= head;
}

// ! QUESTION
void combine(node *head1, node *head2){
    node *p= head1, *q= head2;

    while (p->next != head1)
        p= p->next;
    p->next= head2;

    while(q->next != head2)
        q= q->next;
    q->next= head1;
}
// ! QUESTION
