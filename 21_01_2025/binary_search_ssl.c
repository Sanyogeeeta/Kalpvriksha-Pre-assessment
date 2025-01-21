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

Node* Middle_List(Node* start, Node* end) {
    if (start == NULL) return NULL;
    Node* slow = start, * fast = start;
    while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL) fast = fast->next;
    }
    return slow;
}

void binary_search(Node* start,Node* end,int key){

    if(start==NULL|| end==NULL){
        printf("List is Empty\n");
        return;
    }
    if(start==end) return;

    Node* middle=Middle_List(start,end);    
    if(middle->data==key){
        printf("value found\n");
        return;
    }
    else if(middle->data<key)
        binary_search(middle->next,end,key);
    else if(middle->data>key)
        binary_search(start,middle,key);

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

    if(head==NULL){
        printf("List is Empty\n");
        return 0;
    }
    Node* end=head;
    while(end->next!=NULL){
        end=end->next;
    }
    binary_search(head,end,2);
    freeList(head);
    return 0;
}