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

void insertion_sort(Node** Head){
    Node* next=NULL,* sort=NULL,* current=*Head;
    while(current!=NULL){
        next=current->next;

        if(sort==NULL||sort->data>current->data){
            current->next=sort;
            sort=current;
        }
        else{
            Node* temp=sort;
            while(temp->next!=NULL && temp->next->data<current->data)
                temp=temp->next;
            current->next=temp->next;
            temp->next=current;
        }
        current=next;
    } 
    *Head=sort;  
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
    
    insertion_sort(&Head);
    display(Head);
    return 0;
}




