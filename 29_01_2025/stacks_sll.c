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

void push(node** head,int value){
    node* new_node=create_node(value);
    if(head==NULL)
        *head=new_node;
    new_node->next=*head;
    *head=new_node;
}

void pop(node** head){
    node* temp=*head;
    if(*head==NULL)
    {
        printf("NULL");
        return;
    }
    (*head)=(*head)->next;
    printf("%d\n",temp->data);
    free(temp);
}

void free_stack(node* head){
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
    node* head=NULL;

    scanf("%d",&length);
    int* stack=malloc(sizeof(int)*length);
    while(choice!=3){
        scanf("%d",&choice);
        switch(choice){
            case 1:
                scanf("%d",&value);
                push(&head,value);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                return 0;
        }
    }
    free_stack(head);
    return 0;
}