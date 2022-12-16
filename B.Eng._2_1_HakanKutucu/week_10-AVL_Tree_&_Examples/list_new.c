/**
 * @file list_new.c
 * @author Abdullah Ergul (abdullahergul23@gmail.com)
 * @brief 
 * @version 0.1
 * @date 16-12-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
    In a Binary Tree consisting of nodes which have student information such as name, surname, number and final.
    Write a program that lists the students who have final grade above the avarage of the final grades in the classroom.
    Write the node structure. Note that you should calculate the avarage of the final grades.
    Write codes with only one list function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// BST
typedef struct node {
    char name[20];
    char sname[20];
    double number;
    float final;

    struct node *right;
    struct node *left;
} BTREE;

BTREE *new_node(char *name, double number, float final);
BTREE *insert(BTREE *root, char *name, double number, float final);
void list(BTREE *root, BTREE *main, int x);


int main() {
    // * Get number from user till enter -1
    BTREE *myRoot= NULL;
    char name[20];
    char sname[20];
    double number;
    float final;

    printf("Name: "); scanf("%s",name);
    //printf("Surname: "); scanf("%s",sname);
    printf("Number: "); scanf("%lf",&number);
    printf("Final: "); scanf("%f",&final);
    printf("\n");

    while(number != -1){
        myRoot= insert(myRoot, name, number, final);
        printf("Name: "); scanf("%s",name);
        //printf("Surname: "); scanf("%s",sname);
        printf("Number: "); scanf("%lf",&number);
        printf("Final: "); scanf("%f",&final);
        printf("\n");
    }

    list(myRoot, myRoot, 0);

    return 0;
}

BTREE *new_node(char *name, double number, float final) {
    BTREE *p= (BTREE *)malloc(sizeof(struct node));
    strcpy(p->name, name);  p->number= number; p->final= final;
    p->left= p->right= NULL;
    return p;
}

BTREE *insert(BTREE *root, char *name, double number, float final) {
    if(root==NULL)
        root= new_node(name, number, final);
    else{
        if(number < root->number)
            root->left= insert(root->left, name, number, final);
        else
            root->right= insert(root->right, name,  number, final);
    }
    return root;
}

void list(BTREE *root, BTREE *main, int x) {
    static float sum= 0;
    static float count= 0;

    if (root == NULL)
        return;

    if(x == 0) {
        // sum all nodes
        sum += root->final;
        count++;
        list(root->right, main, 0);
        list(root->left, main, 0);
        x= 1;
    }

    if (main == root && x == 1) {
        // calculate avarage
        float avarage= sum / count;

        // inordered list
        list(root->left, root->left, 1);

        if (root->final > avarage){
            printf("Name: %s  ", root->name);
            //printf("Surname: %s", root->sname);
            printf("Number: %lf  ", root->number);
            printf("final: %f", root->final);
            printf("\n");
        }
        
        list(root->right, root->right, 1);
    }
}
