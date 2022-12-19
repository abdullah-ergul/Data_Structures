/*
    Write a function that adds values of the last and the first node of a circular linked list and insert the sum into the list as the last node.
    You may assume there are at least two nodes in the list. You are not allowed to use any linked list function.
*/

#include <stdio.h>
#include <stdlib.h>


// Linked List
typedef struct node {
    int data;
    struct node *next;
} node;


node *add (node *head) {
    node *iter= head;

    while (iter->next != head)
        iter= iter->next;
    
    node *temp= (node *)malloc(sizeof(node));
    temp->data= head->data + iter->data;

    temp->next= head;
    iter->next= temp;

    return head;
}
