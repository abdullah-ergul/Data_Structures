#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

node *addFront(node *);


int main(){
    
    
    return 0;
}

node *addFront(node *head){
    node *temp= (node *)malloc(sizeof(node));
    if(head == NULL){
        temp->next= temp;
        head= temp;
    }
    else{
        temp->next= head;
        node *last= head;
        while(last->next != head)
            last= last->next;
        last->next= temp;
        head= temp;     // If we want to write addLast() function, we should only delete this line of code.
    }
    return head;
}