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

void deletion(Node* Head,int key){
    Node* temp=Head;
    Node* prev=NULL;

    for(int i=0;temp!=NULL;i++){
        if(temp->data==key){
            prev->next=temp->next;
            free(temp);
            temp=prev->next;
        }
        else{
            prev=temp;
            temp=temp->next;
        }
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
    int n;
    Node* Head=NULL,*cur=NULL;
    int data;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        createNode(&Head,&cur,data);
    }

    int key;
    scanf("%d",&key);
    deletion(Head,key);

    printLinkedList(Head);
    freeLinkedList(Head);
    return 0;
}