/*
    1- Write a program that prints out the degree of each vertex in an undirected graph which is represented by adjency matrix.
    2- Write a function that returns the number of edges in an undirected graphwhich is represented by adjacency matrix.
*/

#include <stdio.h>
#include <stdlib.h>


int degree(int A[6][6], int, int);
int edges(int A[6][6], int);


int main() {
    int i, matrix[6][6] = {
        {0,1,0,0,1,0},
        {1,0,1,1,0,0},
        {0,1,0,1,1,1},
        {0,1,1,0,1,0},
        {0,0,1,1,0,1},
        {0,0,1,0,1,0}
    };

    // 1
    for(i=0 ; i<6 ; i++)
        printf("%d. vertex's degree: %d\n", i+1, degree(matrix,i,6));

    printf("\n--------------------------------\n\n");

    //2
    printf("Number of edges on matrix: %d", edges(matrix, 6));

    return 0;
}

int degree(int A[6][6], int v, int n) {
    int result= 0, i;

    for(i=0 ; i<n ; i++)
        result += A[v][i];

    return result;
}

int edges(int A[6][6], int n) {
    int result= 0, i, j;

    for(i=0 ; i<n ; i++)
        for(j=0 ; j<i ; j++)
            result += A[i][j];
    
    return result;
}
