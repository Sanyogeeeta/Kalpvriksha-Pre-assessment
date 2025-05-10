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

void swap(int* x,int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void bubble_sort(Node* Head){
    Node* outer=Head;
    Node* lptr=NULL;
    int swapped=0;
    while(outer!=NULL && swapped==0){
        Node* inner=Head;
        while(inner->next!=lptr){
            if((inner->data)>(inner->next->data)){
                swap(&inner->data,&inner->next->data);
                swapped=1;
            }
            inner=inner->next;
        }
        outer=outer->next;
        if(swapped==1)
            swapped=0;
    }    
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
    
    bubble_sort(Head);
    display(Head);
    return 0;
}




