#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *next;
} node;

node *addEdge(node *, int);
int outDegree(node *[], int);


int main() {
    int i;
    node *heads[5] = {NULL};
    
    heads[0] = addEdge(heads[0], 1);
    heads[0] = addEdge(heads[0], 2);
    
    heads[1] = addEdge(heads[1], 2);
    heads[1] = addEdge(heads[1], 4);

    heads[2] = addEdge(heads[2], 3);
    heads[2] = addEdge(heads[2], 1);
    heads[2] = addEdge(heads[2], 4);
    heads[2] = addEdge(heads[2], 5);

    heads[3] = addEdge(heads[3], 4);
    heads[3] = addEdge(heads[3], 1);
    heads[3] = addEdge(heads[3], 3);
    heads[3] = addEdge(heads[3], 5);

    heads[4] = addEdge(heads[4], 5);


    for(i=0 ; i<5 ; i++)
        printf("%d -> %d\n", i+1, outDegree(heads,i));

    return 0;
}

node *addEdge(node *head, int x) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;

    if(head == NULL) {
        head = temp;
    }
    else {
        node *p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = temp;
    }
    temp->next = NULL;
    return head;
}

int outDegree(node *heads[], int v) {
    int i, result= 0;
    node *temp = heads[v];
    
    while(temp != NULL) {
        result++;
        temp = temp->next;
    }
    
    return result-1;
}
