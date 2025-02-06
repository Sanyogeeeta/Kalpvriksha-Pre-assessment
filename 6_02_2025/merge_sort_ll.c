#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}node;

node* create(int value){
    node* new=malloc(sizeof(node));
    new->next=NULL;
    new->value=value;
    return new;
}

void insert(node** head,int value){
    node* new=create(value);
    if(*head==NULL){
        *head=new;
    }
    else{
    node* current=*head;
    while(current->next!=NULL)
        current=current->next;
    current->next=new;
    }
}

node* mid(node* head){
    node* slow=head,*fast=head;
    while(fast!=NULL&& fast->next!=NULL){
        fast=fast->next->next;
        if(fast!=NULL){
            slow=slow->next;
        }
    }
    node* temp=slow->next;
    slow->next=NULL;
    return temp;
}

void display(node* head){
    node* temp=head;
    if(head==NULL)return;
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp=temp->next;
    }
}

node* merge(node* head,node* mid){
    if(head==NULL)return mid;
    if(mid==NULL)return head;
    if(head->value<mid->value){
        head->next=merge(head->next,mid);
        return head;
    }
    else{
        mid->next=merge(head,mid->next);
        return mid;
    }
}

node* merge_sort(node* head){
    if(head==NULL||head->next==NULL)return head;
    node* m=mid(head);
    head=merge_sort(head);
    m=merge_sort(m);
    return merge(head,m);
}

int main(){
    struct node* head=NULL;
    int value;

    while(scanf("%d",&value)==1){
        insert(&head,value);
        if(getchar()=='\n')break;
    }

    display(head);
    head=merge_sort(head);
    display(head);
    return 0;
}