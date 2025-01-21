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


void Linear_search(Node* head,int key){
    Node* temp=head;
    int flag=0;
    while(temp!=NULL){
        if(temp->data==key){
            flag=1;
            printf("Element found\n");
            break;
        }
        temp=temp->next;
    }
    if(flag==0)
        printf("Not found\n");
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
    Node* head=NULL;

    fgets(str,sizeof(str),stdin);
    insertion(str,&head);
    Node* end=head;
    while(end->next!=NULL){
        end=end->next;
    }
    Linear_search(head,2);
    return 0;
}




