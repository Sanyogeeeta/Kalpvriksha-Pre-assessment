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

void insertion (char str[],Node** Head){
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

int isPalindrome(Node* Head){
    int flag=0;
    Node* current=Head,*next=NULL,*prev=NULL;
    Node* revHead=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    revHead=prev;
    
    Node* temp1=Head,*temp2=revHead;
    while(temp2!=NULL&& temp1!=NULL){
        if(temp1->data!=temp2->data){
            flag=1;
            break;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return flag;
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
    
    if(isPalindrome(Head)==1)
        printf("Not a Palindrome\n");  
    else
        printf("Its palindrome\n");
    freeList(Head);
    return 0;
}




