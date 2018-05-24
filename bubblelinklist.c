#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

void bubble(Node *current,Node *pnode){
    int temp=0;
    while (current!=NULL){
        pnode=current->next;
        while (pnode!=NULL){
            if (current->data>pnode->data){
                temp=current->data;
                current->data=pnode->data;
                pnode->data=temp;
            }
            pnode=pnode->next;
        }
        current=current->next;
    }
}

void printnode(Node *pnode){
    while (pnode!=NULL){
        printf("%d ",pnode->data);
        pnode=pnode->next;
    }
}

int main(int argc,char *argv[]){
    Node *head,*current,*previous,*pnode;
    int n;
    head=(Node *)malloc(sizeof(Node));
    head->next=NULL;
    current=head;
    printf("link list 1: ");
    for (;;){
        scanf("%d",&n);
        if (n==-1){
            break;
        }
        pnode=(Node *)malloc(sizeof(Node));
        pnode->data=n;
        pnode->next=NULL;
        current->next=pnode;
        current=current->next;
    }
    previous=head->next;
    pnode=previous->next;
    printnode(previous);
    bubble(previous,pnode);
    printf("\n");
    printnode(previous);
    printf("\nlink list 2: ");
    for (;;){
        scanf("%d",&n);
        if (n==-1){
            break;
        }
        pnode=(Node *)malloc(sizeof(Node));
        pnode->data=n;
        pnode->next=NULL;
        current->next=pnode;
        current=current->next;
    }
    previous=head->next;
    pnode=previous->next;
    printnode(previous);
    bubble(previous,pnode);
    printf("\n");
    printnode(previous);
    return 0;
}
