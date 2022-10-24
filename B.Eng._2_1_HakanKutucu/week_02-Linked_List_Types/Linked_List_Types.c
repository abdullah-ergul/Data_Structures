#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};
typedef struct node node;

node *addFront(node *, int);
node *addLast(node *, int);
void printList(node *);
void printReverse(node *, int);
int countList(node *, int);

int main(){
    node *head= (node *)malloc(sizeof(node));

    head->data= 4;
    head->next= NULL;

    head= addFront(head, 2);
    head= addLast(head, 8);
    printList(head);
    printReverse(head, 0);
    printf("Count of node: %d\n",countList(head, 0));
    
    return 0;
}

node *addFront(node *head, int x){
    node *temp= (node *)malloc(sizeof(node));
    temp->data= x;
    temp->next= head;
    head= temp;

    return head;
}

node *addLast(node *head, int x){
    node *temp= (node *)malloc(sizeof(node));
    node *p= head;

    temp->data= x;
    if(head == NULL)
        head= temp;
    else{
        while(p->next != NULL)
            p= p->next;
        p->next= temp;
        temp->next= NULL;
        }

    return head;
}

void printList(node *head){
    node *p= head;
    while(p != NULL){
        printf("%d\n",p->data);
        p= p->next;
    }
    printf("\n--------------------------------\n\n");
}

void printReverse(node *p, int i){
    if(p == NULL)
        return;
    printReverse(p->next, i+1);
    printf("%d\n", p->data);

    if(i == 0)
        printf("\n--------------------------------\n\n");
}

int countList(node *p, int i){
    if(p == NULL)
        return 0;
    return 1 + countList(p->next, i+1);

    if(i == 0)
        printf("\n--------------------------------\n\n");
}
