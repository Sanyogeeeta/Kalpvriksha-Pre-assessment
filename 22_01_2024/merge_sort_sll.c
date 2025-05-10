#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void createNode(Node** Head,int value){
    Node* newElement=(Node*)malloc(sizeof(Node));
    newElement->data=value;
    newElement->next=NULL;
    if(*Head==NULL)
        *Head=newElement;
    else{
        Node* current=*Head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newElement;
    }
}

void insertion(char str[],Node** Head){
    char* ptr=str;
    int value;
    while(*ptr){
        if(isdigit(*ptr)){
            sscanf(ptr,"%d",&value);
            createNode(Head,value);
            while(isdigit(*ptr))
                ptr++;
        }else{
            ptr++;
        }
    }
}

void display(Node* Head){
   if(Head==NULL)
        printf("List is Empty\n");
    else{
         Node* current=Head;
        while(current->next!=NULL){
            printf("%d ",current->data);
            current=current->next;
        }
        printf("%d\n",current->data);
    }
}

Node* partition(Node* head){
    Node* slow=head,* fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        if(fast!=NULL)
            slow=slow->next;
    }
    Node* temp=slow->next;
    slow->next=NULL;
    return temp;
}

Node* merge(Node* first,Node* second){
    if(first==NULL)return second;
    if(second==NULL)return first;
  
    if(first->data<second->data){
        first->next=merge(first->next,second);
        return first;
    }
    else{
        second->next=merge(first,second->next);
        return second;
    }
}

Node* merge_sort(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* second=partition(head);
    head=merge_sort(head);
    second=merge_sort(second);
    return merge(head,second);
}

void freeList(Node* Head) {
    while (Head != NULL) {
        Node* temp = Head;
        Head = Head->next;
        free(temp);
    }
}

int main(){
    char str[500];
    Node* Head=NULL;

    fgets(str,sizeof(str),stdin);
    insertion(str,&Head);
    display(Head);
    
    Head=merge_sort(Head);
    display(Head);
    freeList(Head);
    return 0;
}
