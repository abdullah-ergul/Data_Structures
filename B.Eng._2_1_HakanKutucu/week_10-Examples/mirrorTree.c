/*
    Convert a BST into its Mirror Tree
*/

#include <stdio.h>
#include <stdlib.h>


// Binary Tree
struct node{
    struct node *left;
    struct node *right;
    int data;
};
typedef struct node BTREE;

void mirrorTree (BTREE *);


int main () {


    return 0;
}

void mirrorTree (BTREE *root) {
    if (root == NULL || root->left == root->right)  // root==NULL -OR- root->left and root->right == NULL
        return;
    
    BTREE *temp= root->left;
    root->left= root->right;
    root->right= temp;

    mirrorTree (root->left);
    mirrorTree (root->right);
}
