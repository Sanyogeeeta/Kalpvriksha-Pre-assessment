#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int value;
struct node* next;
}node;

node* create(int value){
    node* new_node=malloc(sizeof(node));
    new_node->value=value;
    new_node->next=NULL;
    return new_node;
}

void insertion(node** head,int value){
    node* temp=*head;    
    if(temp==NULL){
        *head=create(value);
        return;
    }
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=create(value);
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp=temp->next;
    }
}

void partition(node* pivot,node** left,node** right){
    node* temp=pivot->next;
    while(temp){
        node* next=temp->next;
        if(temp->value<pivot->value){
            temp->next=*left;
            *left=temp;
        }
        else{
            temp->next=*right;
            *right=temp;
        }
        temp=next;
    }
}

node* quick_sort(node* head){
    if(head==NULL||head->next==NULL)return head;
    node* right=NULL,*left=NULL;
    node* pivot=head;
    partition(pivot,&left,&right);
    left=quick_sort(left);
    right=quick_sort(right);

    if(left==NULL){
        pivot->next=right;
        return pivot;
    }
    
    node* temp=left;
    while(temp->next!=NULL)
        temp=temp->next;
    
    temp->next=pivot;
    pivot->next=right;
    return left;
}

int main(){
    node* head=NULL;
    int value;
    while(scanf("%d",&value)==1&& value != -1){
        insertion(&head,value);
    }
    
    display(head);
    head=quick_sort(head);
    display(head);
    return 0;
}