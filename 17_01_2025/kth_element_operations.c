#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void createNode(Node **Head,Node **cur,int data){
    Node* new=(Node*)malloc(sizeof(Node));
    new->data=data;
    new->next=NULL;

    if(*Head==NULL)
        *Head=new;
    else    
        (*cur)->next=new;
    (*cur)=new;
}

int length_of_LinkedList(Node* Head){
    Node* temp=Head;
    int length=0;
    while(temp!=NULL){
        length+=1;
        temp=temp->next;
    }
    return length;
}

void printLinkedList(Node* Head){
    Node* temp=Head;

    while(temp->next!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}

void print_kth_element(Node* Head,int k){
    
    Node* temp=Head;
    int length=length_of_LinkedList(Head);
    for(int i=1;i<=length;i++){
        if(i%k==0){
            printf("%d ",temp->data);
        }
        temp=temp->next;
    }

}

int kth_element_sum(Node* Head,int k){
    Node* temp=Head;
    int length=length_of_LinkedList(Head);
    int sum=0;

    for(int i=1;i<=length;i++){
        if(i%k==0){
            sum+=temp->data;
        }
        temp=temp->next;
    }
    return sum;
}

void remove_kth_element(Node* Head,int k){
    Node* temp=Head,*prev=NULL;
    int length=length_of_LinkedList(Head);    
    for(int i=1;i<=length;i++){
        if(i%k==0){
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

int main(){
    int n,data;
    scanf("%d",&n);

    Node* Head=NULL,*cur=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        createNode(&Head,&cur,data);
    }

    printLinkedList(Head);
    int k;

    scanf("%d",&k);
    print_kth_element(Head,k);

    int sum=kth_element_sum(Head,k);
    printf("%d\n",sum);

    remove_kth_element(Head,k);
    if(k==1)
        Head=NULL;
    printLinkedList(Head);    

    return 0;
}