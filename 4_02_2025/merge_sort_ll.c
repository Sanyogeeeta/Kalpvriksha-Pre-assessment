#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}node;

node* create_node(int value){
    node* new_node=malloc(sizeof(node));
    new_node->next=NULL;
    new_node->value=value;
    return new_node;
}

void insertion(node** head,int value){
    node* new=create_node(value);
    if(*head==NULL){
        *head=new;
        return;
    }
    node* current=*head;
    while(current->next!=NULL)
        current=current->next;
    
    current->next=new;
}

node* middle_element(node* l){
    node* slow=l,*fast=l;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        if(fast!=NULL)
            slow=slow->next;
    }
    node* current=slow->next;
    slow->next=NULL;
    return current;
}

void display(node* head){
    if(head==NULL)return;
    node* current=head;
    while(current!=NULL){
        printf("%d ",current->value);
        current=current->next;
    }
    printf("\n");
}

node* merge(node* l,node* r){
    node* current=NULL;
    node* head=NULL;
    node* temp1=l;
    node* temp2=r;
    while(temp1!=NULL && temp2!=NULL ){
        if(temp1->value<temp2->value){
            if(head==NULL){
                current=temp1;
                head=temp1;
            }
            else{
            current->next=temp1;
            current=temp1;
            }
            temp1=temp1->next;
        }
        else if(temp1->value==temp2->value){
            if(head==NULL){
                current=temp1;
                head=temp1;
            }
            else{
            current->next=temp1;
            current=temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else{
            if(head==NULL){
                current=temp2;
                head=temp2;
            }
            else{
            current->next=temp2;
            current=temp2;           
            }
            temp2=temp2->next; 
        }
    }

    while(temp1!=NULL){
        current->next=temp1;
        current=temp1;
        temp1=temp1->next;
    }
    while(temp2!=NULL&& temp2!=NULL){
        current->next=temp2;
        current=temp2;
        temp2=temp2->next;
    }
    return head;
}

node* merge_sort(node* left){
    if (left == NULL || left->next==NULL) {
        return left;
    }
    node* mid=middle_element(left);
    node* left_sorted=merge_sort(left);
    node* right_sorted=merge_sort(mid);
    return merge(left_sorted,right_sorted); 
}

int main(){
    int value;
    node* head=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        insertion(&head,value);
    }

    display(head);
    node* left=head;
    node* right=head;

    while(right->next!=NULL)
        right=right->next;

    head=merge_sort(left);
    display(head);
    return 0;
}