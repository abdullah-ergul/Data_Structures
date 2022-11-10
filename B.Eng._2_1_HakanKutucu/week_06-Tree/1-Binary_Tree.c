#include <stdio.h>
#include <stdlib.h>


// Binary Tree
struct node{
    struct node *left;
    struct node *right;
    int data;
};
typedef struct node *BTREE;

BTREE new_node(int);
BTREE insert(BTREE, int);

int main(){
    // * Get number from user till enter -1
    BTREE myRoot= NULL;
    int i;

    scanf("%d",&i);
    while(i != -1){
        myRoot= insert(myRoot,i);
        scanf("%d",&i);
    }

    return 0;
}

BTREE new_node(int data){
    BTREE p;
    p= (BTREE)malloc(sizeof(struct node));
    p->data= data;
    p->left= p->right= NULL;
    return p;
}

BTREE insert(BTREE root, int x){
    if(root==NULL)
        root=new_node(x);
    else{
        if(x<root->data)
            root->left= insert(root->left,x);
        else
            root->right= insert(root->right,x);
    }
    return root;
}
