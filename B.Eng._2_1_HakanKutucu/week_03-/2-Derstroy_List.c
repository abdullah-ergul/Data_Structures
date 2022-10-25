#include <stdio.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

node *destroy(node *);


int main(){
    
    
    return 0;
}

node *destroy(node *head){
    node *temp=head;
    while(head != NULL){
        head= head->next;
        free(temp);
        temp= head;
    }
    return NULL;
}

node *destroyRecursive(node *p){
    if(p == NULL)
        return NULL;
    destroyRecursive(p->next);
    free(p);
    return NULL;
}
