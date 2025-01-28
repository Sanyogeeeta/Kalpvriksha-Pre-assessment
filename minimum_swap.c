#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

/*
You are given a singly linked list containing integers. Your task is to sort the linked list in ascending order using Selection Sort in such a way that the minimum number of swaps is performed.
Additionally, your program should count and display the number of swaps made during the sorting process.
*/

typedef struct node{
    int value;
    struct node*  next;
}node;

typedef struct ssl{
    node* head;
    node* tail;
}ssl;

void createNode(ssl *s,int value){
    node* newnode=malloc(sizeof(node));
    newnode->value=value;
    newnode->next=NULL;
    if(s->head==NULL){
        s->head=newnode;
        s->tail=newnode;
        return;
    }
    s->tail->next=newnode;
    s->tail=newnode;
}

void display(ssl s){
    node* temp=s.head;
    if(s.head==NULL){
        printf("Empty\n");
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp=temp->next;
    }
}

void FreeList(ssl* s){
    while(s->head!=NULL){
        node* toFree=s->head;
        s->head=toFree->next;
        free(toFree);        
    }
}

void swap(int* x,int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int selection_sort(ssl* s){
    node* outer=s->head;
    int count=0;
    while(outer!=NULL){
        node* min=outer;
        node* inner=outer->next;
        while(inner!=NULL){
            if(min->value>inner->value)
                min=inner;
            inner=inner->next;
        }
        if(outer!=min){
            swap(&outer->value,&min->value);
            count++;
        }
        outer=outer->next;
    }
    return count;
}

int main(){
    ssl s;
    s.tail=NULL;
    s.head=NULL;

    int value;
    char str[500];
    char* ptr=str;

    while(scanf("%d",&value)==1){
        createNode(&s,value);
        if(getchar()=='\n')break;
    }
    display(s);

    int swap_count=selection_sort(&s);
    printf("\n%d\n",swap_count);
    display(s);
    return 0;
}