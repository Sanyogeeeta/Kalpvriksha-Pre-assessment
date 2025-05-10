#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}node;

node* create_node(int value){
    node* new_node=malloc(sizeof(node));
    new_node->next=new_node;
    new_node->value=value;
    return new_node;
}

void insertion(node** head,int value){
    node* new_node=create_node(value);
    if(*head==NULL){
        *head=new_node;
        return;
    }
    node* current=*head;
    while(current->next!=*head){
        current=current->next;
    }
    current->next=new_node; 
    new_node->next=*head;
}

void display(node* head){
    node* current=head;
    if(head=NULL){
        return;
    }
    while(current!=head){
        printf("%d ",current->value);
        current=current->next;
    }
    printf("%d\n",current->value);
}

void delete(node** head,int value){
    node* current=*head,* prev;
    if(*head==NULL)return;
    
    while(current!=*head){
        if(current->value==value){
            prev->next=current->next;
            printf("%d Deleted\n",value);
            return;
        }
        prev=current;
        current=current->next;
    }
}

int main(){
    struct node* head=NULL;
    int value;

    while(scanf("%d",&value)==1){
        insertion(&head,value);
        if(getchar()=='\n')break;
    }
    display(head);

    delete(&head,3);
    display(head);
    return 0;
}