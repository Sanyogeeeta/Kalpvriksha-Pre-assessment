#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

Node* Head=NULL;

void createNode(int value){
    Node* newElement;
    newElement=(Node*)malloc(sizeof(Node));
    newElement->value=value;
    newElement->next=NULL;
    
    if(Head==NULL)
        Head=newElement;
    else{
        Node* current=Head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newElement;
    }
}

void display(){
    Node* temp=Head;
    if(Head==NULL)
        return;
    else{
        while(temp->next!=NULL){
            printf("%d ",temp->value);
            temp=temp->next;
        }
        printf("%d",temp->value);
    }
}

void FreeList(){
    Node* temp=Head;
    while(Head!=NULL){
        Head=Head->next;
        free(temp);
        temp=Head;
    }
}

Node* MiddleElementRemove(){
    Node* current=Head,*prev=NULL,*temp=Head;
    
    int length=0;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    } 
    
    if(Head==NULL)
        return NULL;   
    
    else if(length==1){
        free(Head);
        Head=NULL;
    }
    
    else{
        
        for(int i=0;i<length/2;i++){
            prev=current;
            current=current->next;
        }
        if(prev!=NULL)
            prev->next=current->next;
        free(current);  
    }
    return Head;
}

int main() {
    int value;
    
    while(scanf("%d",&value)==1){
        createNode(value);
        if(getchar()=='\n')break;
    }
    
    Head=MiddleElementRemove();  
    display();
    FreeList();
    return 0;
}
