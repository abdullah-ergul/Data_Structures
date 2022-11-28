#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
    int num;
    char name[20];
    char sName[20];
    struct Student *next;
    struct Student *prev;
} node;

node *add(node *,int, char *, char *);



int main(){


    return 0;
}

// ! QUESTION
node *add(node *head, int num, char *name, char *sName){
    if(head==NULL){
        head->num= num; strcpy(head->name,name); strcpy(head->sName,sName); head->next=NULL; head->prev=NULL;
    }
    else if(head->num > num){
        node *temp= (node *)malloc(sizeof(node));
        temp->num= num; strcpy(temp->name,name); strcpy(temp->sName,sName); temp->next=head; temp->prev=NULL;
        head->prev= temp;
        head= temp;
    }
    else{
        node *p=head;
        while(p->next->num < num && p->next != NULL)
            p= p->next;
        
        node *temp= (node *)malloc(sizeof(node));
        temp->num= num; strcpy(temp->name,name); strcpy(temp->sName,sName); temp->next=p->next; temp->prev=p;
        p->next= temp;
        if(temp->next != NULL)
            temp->next->prev= temp;
    }
    return head;
}
// ! QUESTION
