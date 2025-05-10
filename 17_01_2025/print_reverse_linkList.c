#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void createNode(Node **Head,Node** cur,int data){
    Node* new=(Node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    if(*Head==NULL){
        *Head=new;
    }
    else{
        (*cur)->next=new;
    }
    *cur=new;
}

void printLinkedList(Node* Head){
    Node* temp=Head;
    while(temp->next!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}

Node* reverseLinkedList(Node* Head){

    if(Head==NULL||Head->next==NULL)
        return Head;
        
    Node* temp=reverseLinkedList(Head->next);
    Head->next->next=Head;
    Head->next=NULL;
    return temp;
}

int main(){
    int n;
    Node* Head=NULL,*cur=NULL;
    int data;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&data);
        createNode(&Head,&cur,data);
    }

    printLinkedList(Head);
    Head=reverseLinkedList(Head);
    printLinkedList(Head);

    return 0;
}