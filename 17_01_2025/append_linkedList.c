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

void appendLinkedList(Node** Head,Node* Head1,Node* Head2){
    Node* temp=Head1;
    Node* cur=NULL;
    while(temp!=NULL){
        int data=temp->data;
        createNode(Head,&cur,data);
        temp=temp->next;
    }
    temp=Head2;
    while(temp!=NULL){
        int data=temp->data;
        createNode(Head,&cur,data);
        temp=temp->next;
    }
}

void freeLinkedList(Node* Head) {
    Node* temp;
    while (Head != NULL) {
        temp = Head;
        Head = Head->next;
        free(temp);
    }
}

void printLinkedList(Node* Head){
    Node* temp=Head;
    while(temp->next!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}

int main(){
    int n1,n2;
    Node* Head1=NULL,*cur1=NULL;
    Node* Head2=NULL,*cur2=NULL;
    Node* Head=NULL;
    int data;

    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        scanf("%d",&data);
        createNode(&Head1,&cur1,data);
    }

    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        scanf("%d",&data);
        createNode(&Head2,&cur2,data);
    }

    // printLinkedList(Head1);
    // printLinkedList(Head2);

    appendLinkedList(&Head,Head1,Head2);
    printLinkedList(Head);
    freeLinkedList(Head1);
    freeLinkedList(Head2);
    freeLinkedList(Head);
    return 0;
}