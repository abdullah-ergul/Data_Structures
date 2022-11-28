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
int getInfo(BTREE *, int);


int main(){
    BTREE *myRoot= NULL;
    int i;

    scanf("%d",&i);
    while(i != -1){
        myRoot= insert(myRoot,i);
        scanf("%d",&i);
    }

    printf("%d",getInfo(myRoot,2));

}

// ! QUESTION
int getInfo(BTREE *root, int lvl){
    static int num= 0;
    
    if(root==NULL)
        return 0;
    else if(0 == lvl--){
        // num++; // * lvl's data count
        num += root->data; // * lvl's data sum
        return 1;
    }
    else{
        int a;
        a= getInfo(root->left,lvl);
        a= getInfo(root->right,lvl);
    }
    return num;
}
// ! QUESTION

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
