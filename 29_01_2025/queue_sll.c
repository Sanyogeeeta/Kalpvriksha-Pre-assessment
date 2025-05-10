#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* create_node(int value){
    node* new_node=malloc(sizeof(node));
    new_node->next=NULL;
    new_node->data=value;
    return new_node;
}

void enqueue(node** head,node** tail,int value){
    node* new_node=create_node(value);
    if(*head==NULL){
        *head=new_node;
        *tail=new_node;
        return;
    }
    (*tail)->next=new_node;
    *tail=new_node;    
}

void dequeue(node** head,node** tail){
    if(*head==NULL||*tail==NULL)
    {
        printf("Empty\n");
        return;
    }
    *head=(*head)->next;
}

void free_queue(node* head){
    node* temp=head;
    while(temp!=NULL){
        node* todelete=temp;
        temp=temp->next;
        free(todelete);
    }
}

int main(){

    int choice=0,length;
    int value;
    node* head=NULL,*tail=NULL;
    while(choice!=3){
        scanf("%d",&choice);
        switch(choice){
            case 1:
                scanf("%d",&value);
                enqueue(&head,&tail,value);
                break;
            case 2:
                dequeue(&head,&tail);
                break;
            case 3:
                return 0;
        }
    }
    free_queue(head);
    return 0;
}