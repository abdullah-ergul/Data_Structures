#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct node {
    int data;
    struct node *next;
} node;

node *randomHundred();
void printList(node *);
node *bubbleSort(node *);


int main() {
    node *head = randomHundred();
    printList(head);

    head = bubbleSort(head);
    printList(head);

    return 0;
}

node *randomHundred() {
    node *head = (node *)malloc(sizeof(node));
    int i;
    srand(time(NULL));

    node *iter = head;
    for(i=0 ; i<100 ; i++) {
        iter->data = rand() % 101;

        if(i == 99) {
            iter->next = NULL;
        }
        else {
            iter->next = (node *)malloc(sizeof(node));
            iter = iter->next;
        }
    }
    return head;
}

void printList(node *head) {
    node *iter = head;

    while(iter->next != NULL) {
        printf("%d - ", iter->data);
        iter = iter->next;
    }
    printf("%d\n\n--------------------------\n\n", iter->data);
}

node *bubbleSort(node *head) {
    node *iter = head, *temp, *temp2;
    int i, j;

    for(i=0 ; i<100 ; i++) {
        for(j=0 ; j<98 ; j++) {
            if(j==0 && iter->next->data < iter->data) {
                iter = head->next;

                head->next = iter->next;
                iter->next = head;
                head = iter;
            }
            else if(iter->next->next->data < iter->next->data) {
                temp = iter->next;
                temp2 = temp->next;

                temp->next = temp2->next;
                temp2->next = temp;
                iter->next = temp2;
            }
            iter = iter->next;
        }
        iter = head;
    }
    return head;
}
