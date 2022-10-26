#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

bool function(node *, int);


int main(){
    
    
    return 0;
}

bool serach(node *p, int x){
    while(p->data != x && p != NULL)
        p= p->next;
    if(p == NULL)
        return false;
    return true;
}