#include <stdio.h>
#include <stdlib.h>

// Binary Tree
struct node{
    struct node *left;
    struct node *right;
    int data;
};
typedef struct node BTREE;

BTREE *new_node(int);
BTREE *insert(BTREE *, int);
BTREE *oddBST(BTREE *);
void preorder(BTREE *);

int main(){
    BTREE *myRoot= NULL;
    int i;

    scanf("%d",&i);
    while(i != -1){
        myRoot= insert(myRoot,i);
        scanf("%d",&i);
    }

    BTREE *newRoot= oddBST(myRoot);
    preorder(newRoot);
}

BTREE *new_node(int data){
    BTREE *p;
    p= (BTREE *)malloc(sizeof(struct node));
    p->data= data;
    p->left= p->right= NULL;
    return p;
}

BTREE *insert(BTREE *root, int x){
    if(root==NULL)
        root= new_node(x);
    else{
        if(x<root->data)
            root->left= insert(root->left,x);
        else
            root->right= insert(root->right,x);
    }
    return root;
}

BTREE *oddBST(BTREE *oldRoot){
    BTREE static *newRoot;
    
    if(newRoot == NULL){
        if(oldRoot->data%2 == 1)
            newRoot= insert(newRoot, newRoot->data);
        else{
            oldRoot= oldRoot->left
        }
    }
    
    return newRoot;
}

    // if(newRoot->data < oldRoot->data)
    //     newRoot= insert(newRoot->left, oldRoot->data);
    // else
    //     newRoot= insert(newRoot->right, oldRoot->data);

void preorder(BTREE *root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
