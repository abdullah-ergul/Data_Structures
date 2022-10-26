#include <stdio.h>

struct node{
    struct node *previous;
    int data;
    struct node *next;
};
typedef struct node node;

node *addFront(node *, int);
node *addEnd(node *, int);
node *delete(node *, int);


int main(){

    
    return 0;
}

node *addFront(node *head, int x){
    node *temp= (node *)malloc(sizeof(node));
    temp->data= x;
    temp->next= head;
    temp->previous= NULL;
    if(head != NULL)
        head->previous= temp;
    head= temp;

    return head;   
}

node *addEnd(node *head, int x){
    node *temp= (node *)malloc(sizeof(node));
    temp->data= x;
    temp->next= NULL;
    if(head == NULL){
        temp->previous= NULL;
        head= temp;
    }
    else{
        node *last= head;
        while(last->next != NULL)
            last= last->next;
        temp->previous= last;
        last->next= temp;
    }
    
    return head;
}

node *delete(node *head, int x){
    if(head != NULL){
        node *temp= head;
        if(head->data == x){
            head= head->next;
            free(temp);
            head->previous= NULL;
        }
        else{
            while(temp->data != x && temp != NULL)
                temp= temp->next;
            
            if(temp == NULL)
                return head;
            temp->previous->next= temp->next;
            if(temp->next != NULL)
                temp->next->previous= temp->previous;
            free(temp);
        }
    }
    return head;
}