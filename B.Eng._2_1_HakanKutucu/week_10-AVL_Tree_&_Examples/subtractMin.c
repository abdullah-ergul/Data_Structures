/*
    Write a function substractMin that substacts the smallest node value from all node (including itself) in the linked list. Suppose the list stores the following elements.
    
    for ex: [8,4,7,2,9,4,5,3], if you made the call of substractMin(head), the list would then store the elements:
            [6,2,5,0,7,2,3,1]
*/

#include <stdio.h>
#include <stdlib.h>


// Linked List
typedef struct node {
    int data;
    struct node *next;
} node;

node *subtractMin (node *);


int main () {


    return 0;
}

node *subtractMin (node *head) {
    if (head == NULL)
        return NULL;

    int min= head->data;
    node *iter= head->next;

    while (iter != NULL) {
        if (iter->data < min)
            min= iter->data;
        iter= iter->next;
    }

    iter= head;
    while (iter != NULL) {
        iter->data -= min;
        iter= iter->next;
    }

    return head;
}
