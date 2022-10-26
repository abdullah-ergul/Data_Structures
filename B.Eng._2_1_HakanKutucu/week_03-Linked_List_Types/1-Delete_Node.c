#include <stdio.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

node *delete(node *, int);


int main(){

    
    return 0;
}

node *delete(node *head, int x){
    if(head != NULL){
        node *temp= head;
        if(head->data == x){
            head= head->next;
            free(temp);
        }
        else{
            while(temp->next->data != x && temp->next != NULL)
                temp= temp->next;

            if(temp->next == NULL)
                return head;
            node *deleted= temp->next;
            temp->next= deleted->next;
            free(deleted);
        }
    }
    return head;
}
