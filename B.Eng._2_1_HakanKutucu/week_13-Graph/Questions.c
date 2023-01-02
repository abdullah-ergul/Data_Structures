#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *next;
} node;

int degree(int A[10][10], int, int);
int outDegree(node *[], int);
int edges(int A[10][10], int );


int main() {


    return 0;
}

// Write a function that return the degree of a given vertex in an undirected graph which is represented by adjacency matrix.
int degree(int A[10][10], int v, int n) {
    int result= 0, i;

    for(i=0 ; i<n ; i++)
        result += A[v][i];

    return result;
}

// Write a function that return the out degree of a given vertex in an directed graph which is represented by adjacency list.
int outDegree(node *heads[], int v) {
    int result= 0;
    node *temp= heads[v];

    while(temp != NULL) {
        result++;
        temp = temp->next;
    }
    return result-1;
}

// Write a function that returns the number of edges in an undirected graphwhich is represented by adjacency matrix.
int edges(int A[10][10], int n) {
    int result= 0, i, j;

    for(i=0 ; i<n ; i++)
        for(j=0 ; j<i ; j++)
            result += A[i][j];
    
    return result;
}

// Write a function that returns true if there is a path between two given vertices in an undirected graph which is represented by matrix.
