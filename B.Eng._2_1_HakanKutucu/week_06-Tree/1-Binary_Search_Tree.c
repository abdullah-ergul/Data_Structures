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
void insertVoid(BTREE, int);
void preorder(BTREE);
void inorder(BTREE);
void postorder(BTREE);

int main(){
    // * Get number from user till enter -1
    BTREE myRoot= NULL;
    int i;

    scanf("%d",&i);
    while(i != -1){
        myRoot= insert(myRoot,i);
        scanf("%d",&i);
    }

    scanf("%d",&i);
    while(i != -1){
        insertVoid(myRoot,i);
        scanf("%d",&i);
    }

    printf("\nPreordered BST  = "); preorder(myRoot);
    printf("\nInordered BST   = "); inorder(myRoot);
    printf("\nPostordered BST = "); postorder(myRoot);

    return 0;
}

BTREE new_node(int data){
    BTREE p;
    p= (BTREE)malloc(sizeof(struct node));
    p->data= data;
    p->left= p->right= NULL;
    return p;
}

void insertVoid(BTREE root, int x){
    if(root->right == NULL && x > root->data || root->left == NULL && x < root->data){
        if(x < root->data)
            root->left= new_node(x);
        else
            root->right= new_node(x);
    }
    else{
        if(x < root->data)
            insertVoid(root->left,x);
        else
            insertVoid(root->right,x);
    }
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

void preorder(BTREE root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(BTREE root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(BTREE root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
