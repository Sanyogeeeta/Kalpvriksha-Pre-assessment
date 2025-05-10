#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* IntersectionList(Node* Head1,Node* Head2){
    Node* temp1=Head1;
    Node* hashNode[100];
    int index=0;
    while(temp1!=NULL){
        hashNode[index++]=temp1;
        temp1=temp1->next;
    }
    for(int i=0;i<index;i++){
        Node*temp2=Head2;
        while(temp2!=NULL){
            if(temp2==hashNode[i])
                return temp2;
            temp2=temp2->next;
        }
    }
    return NULL;
}

int main(){
    Node* head1 = malloc(sizeof(Node));
    Node* head2 = malloc(sizeof(Node));
    head1->data = 1;
    head1->next=malloc(sizeof(Node));
    head1->next->data=3;
    head1->next->next=malloc(sizeof(Node));
    head1->next->next->data=1;
    head1->next->next->next=malloc(sizeof(Node));
    head1->next->next->next->data=2;
    head1->next->next->next->next=malloc(sizeof(Node));
    head1->next->next->next->next->data=3;
    head2->data = 3;
    //head2->next=head1->next->next->next;
    head2->next=malloc(sizeof(Node));
    head2->next->data=4;
    Node* result=IntersectionList(head1,head2);
    if(result==NULL)
        printf("NULL");
    else
        printf("%d\n",result->data);

    return 0;
}
