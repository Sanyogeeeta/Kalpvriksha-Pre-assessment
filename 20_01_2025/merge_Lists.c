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

void insertion (char str[],Node** Head){
    char* ptr=str;
    int value;
    while(*ptr){
        if(isdigit(*ptr)||*ptr=='-'){
            sscanf(ptr,"%d",&value);
            createNode(Head,value);
            while(isdigit(*ptr))
                ptr++;
        }else{
            ptr++;
        }
    }
}

Node* UnionList(Node* Head1,Node* Head2){
    Node* temp1=Head1;
    Node* temp2=Head2;
    Node* Head=NULL;
    Node* current=NULL;
    if(temp1==NULL)return Head2;
    if(temp2==NULL)return Head1;
    if(temp1->data<temp2->data){
        Head=Head1;
        temp1=temp1->next;
    }
    else{
        Head=Head2;
        temp2=temp2->next;
    }
    current=Head;
    while(temp1!=NULL && temp2!=NULL){
        
        if(temp1->data<temp2->data)
        {
            current->next=temp1;
            temp1=temp1->next;
        }
        else{
           current->next=temp2;
            temp2=temp2->next;
        }
        current=current->next;
    }
    while(temp1!=NULL){
        current->next=temp1;
        temp1=temp1->next;
        current=current->next;
    }
    while(temp2!=NULL){
        current->next=temp2;
        temp2=temp2->next;
        current=current->next;
    }
    return Head;
}

int main(){
    char str[500];
    Node* Head1=NULL,* Head2=NULL,* Head=NULL;

    fgets(str,sizeof(str),stdin);
    insertion(str,&Head1);
    display(Head1);

    fgets(str,sizeof(str),stdin);
    insertion(str,&Head2);
    display(Head2);

    Head=UnionList(Head1,Head2);
    display(Head);
    return 0;
}