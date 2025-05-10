#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

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

void selection_sort(ssl* s){
    node* outer=s->head;
    while(outer!=NULL){
        node* min_node=outer;
        node* inner=outer->next;
        while(inner!=NULL){
            if(inner->value < min_node->value){
                min_node=inner;
            }
            inner=inner->next;
        }
        swap(&min_node->value,&outer->value);
        outer=outer->next;
    }
}

int main(){
    ssl s;
    s.tail=NULL;
    s.head=NULL;

    int value;
    char str[500];
    char* ptr=str;

    fgets(str,sizeof(str),stdin);
    while(*ptr!='\n'){
        if(isdigit(*ptr)){
            sscanf(ptr,"%d",&value);
            createNode(&s,value);
            while(isdigit(*ptr))
            ptr++;
        }
        else{
            ptr++;
        }
    }
    display(s);

    selection_sort(&s);
    display(s);
    return 0;
}