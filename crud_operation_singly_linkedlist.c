#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* Head=NULL;

Node* createNode(int value){
    Node* newElement=(Node*)malloc(sizeof(Node));
    newElement->data=value;
    newElement->next=NULL;
    return newElement;
}

int isEmpty(){
    int flag=0;
    if(Head==NULL){
        printf("List is Empty\n");
        flag=1;
    }
    return flag;
}

int ListLength(){
    int length=0;
    Node* temp=Head;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}

void  insertAtBeginning(int value){
    Node* newElement=createNode(value);
    newElement->next=Head;
    Head=newElement;
}

void insertAtEnd(int value){
    Node* newElement=createNode(value);
    if(Head==NULL){
        Head=newElement;
    }
    else{
        Node* temp=Head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newElement;
    }
}

void  insertAtPosition(int position,int value){
    int length=ListLength();
    if(position==1){
        insertAtBeginning(value);
        return;
    }
    else if(Head==NULL||position<1||position>length+1){
        printf("Invalid\n");
    } 
    else{
        Node* temp=Head,*prev=NULL;
        Node* newElement=createNode(value);
        while(position!=1 && temp!=NULL){
            position--;
            prev=temp;
            temp=temp->next;
        }
        prev->next=newElement;
        newElement->next=temp;
    }
}

void display(){
    Node* temp=Head;
    if(isEmpty())
        return;
    else{
        while(temp->next!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}

void  updateAtPosition(int position,int newValue){
    Node* temp=Head;
    int pos=position;
    int length=ListLength();
    if(temp==NULL||position<1||position>length)
        printf("Invalid position\n");
    else{
        while(pos!=1 && temp!=NULL){
            temp=temp->next;
            pos--;
        }
        temp->data=newValue;
    }
}

void  deleteAtBeginning(){
    if(isEmpty())
        return;
    else{
        Node* temp=Head;
        Head=temp->next;
        free(temp);
    }
}

void deleteAtEnd(){

    if(isEmpty())
        return;

    Node* temp=Head,*prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    if(prev==NULL)
        Head=NULL;
    else
        prev->next=NULL;
    free(temp);    
}

void  deleteAtPosition(int position){
    Node* temp=Head,*prev=NULL;
    int pos=position;
    int length=ListLength();
    if(isEmpty())
        return;
        
    if(position<=0||position>length){
        printf("Invalid position\n");
    }
    else if(position==1){
        deleteAtBeginning();
        return;
    }
    else{
        while(pos!=1 && temp->next!=NULL){
            pos--;
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);  
    } 
}

int main(){
    int n,value,position,choice;
    scanf("%d",&n);

    while(n--){
        scanf("%d",&choice);
        switch(choice){
            case 1:
                scanf("%d",&value);
                insertAtEnd(value);
                break;
            case 2:
                scanf("%d",&value);
                insertAtBeginning(value);
                break;
            case 3:
                scanf("%d %d",&position,&value);
                insertAtPosition(position,value);
                break;
            case 4:
                display();
                break;
            case 5:
                scanf("%d %d",&position,&value);
                updateAtPosition(position,value);
                break;
            case 6:
                 deleteAtBeginning();
                break;
            case 7:
                deleteAtEnd();
                break;
            case 8:
                scanf("%d",&position);
                deleteAtPosition(position);
                break;            
        }
    }
    return 0;
}