/*
    In a Binary Tree consisting of nodes which have student information such as name, surname, number and final.
    Write a program that lists the students who have final grade above the avarage of the final grades in the classroom.
    Write the node structure. Note that you should calculate the avarage of the final grades.
*/

#include <stdio.h>
#include <stdlib.h>


// BST
typedef struct node {
    char name[20];
    char sname[20];
    double number;
    float final;

    struct node *right;
    struct node *left;
} BTREE;


void list (BTREE *root, float avarage) {
    if (root == NULL)
        return;
    if (root->final > avarage){
        printf("Name: %s", root->name);
        printf("Surname: %s", root->sname);
        printf("Number: %lf", root->number);
        printf("final: %f", root->final);
    }

    list(root->right, avarage);
    list(root->left, avarage);
}

float avarage (BTREE *root) {
    return sum_nodes(root) / size(root);
}

float sum_nodes (BTREE *root) {
    if (root == NULL)
        return 0;
    return root->final + sum_nodes(root->left) + sum_nodes(root->right);
}

float size (BTREE *root) {
    if (root == NULL)
        return 0;
    return 1 + size(root->left) + size(root->right);
}
