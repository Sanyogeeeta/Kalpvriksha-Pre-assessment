#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}stack;

int is_empty(stack* head){
    return head==NULL;
}

stack* create_node(int value){
    stack* new_node=malloc(sizeof(stack));
    new_node->data=value;
    new_node->next=NULL;
    return new_node;    
}

void pop(stack** head){
    if(is_empty(*head)){
        printf("Stack is Empty\n");
        return;
    }
    stack* temp=*head;
    *head=(*head)->next;
    free(head);
}

int peek(stack* head){
    if(is_empty(head)){
        printf("Stack is Empty\n");
        return -1;
    }
    return head->data;
}

void push(stack** head,int value){
    stack* new=create_node(value);
    new->next=(*head);
    (*head)=new;
}

void free_stack(stack* head){
    stack* temp=head;
    while(temp!=NULL){
        stack* tofree=temp;
        temp=temp->next;
        free(tofree);                
    }
}

int main(){
    stack* head=NULL;
    
    int choice=0,value;
    while(choice!=5){
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
            printf("%d",peek(head));
            break;
            case 4:
            is_empty(head)?printf("True\n"):printf("False\n");
            break;
            case 5:
            free_stack(head);
            head=NULL;
            return 0;
        }    
    }
    return 0;
}