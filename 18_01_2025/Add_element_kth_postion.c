#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node* next;
}Node;

Node* Head;
int ListLength(){
    int length=0;
    Node* temp=Head;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}

void Add_At_Position(int position,int value){
    Node* newElement=(Node*)malloc(sizeof(Node));
    if(newElement==NULL)
        return;
    newElement->data=value;
    newElement->next=NULL;

    int length=ListLength();
    int pos=0;
    if(Head==NULL){
        Head=newElement;
    }
    else if(position<=0||position>length+1)
        return;
    else if(position==1){
        newElement->next=Head;
        Head=newElement;
    }
    else{
        Node* current=Head,*prev=NULL;
        while(pos<position-1 && current!=NULL){
            current=current->next;
            pos++;
        }
        newElement->next=current->next;
        current->next=newElement;
    }
}

void display(){
    Node* current=Head;
    if(Head==NULL)
        return;
    while(current->next!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("%d\n",current->data);
}

int main(){

    int value,position;
    while(scanf("%d %d",&position,&value)==2){
        Add_At_Position(position,value);
        if(getchar()=='\n')break;
    }

    display();
}