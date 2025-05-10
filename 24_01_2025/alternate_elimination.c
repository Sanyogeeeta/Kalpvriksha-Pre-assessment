#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}list;


void create_node(list** head,int value){
    list* new_node=malloc(sizeof(list));
    new_node->next=NULL;
    new_node->value=value;
    if(*head==NULL){
        *head=new_node;
        return;
    }
    list* current=*head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=new_node;
}

void remove_alternate(list** head){
    list* toFree=*head;
    *head=toFree->next;
    free(toFree);
    list* current=*head;
    while(current!=NULL&&current->next!=NULL){
        toFree=current->next;
        current->next=current->next->next;
        free(toFree);
        current=current->next;
    }
}

void reverse_list(list** head){
    list* current=*head,*next=NULL,*prev=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}

void display(list* head){
    if(head==NULL)
        return;
    list* current=head;
    while(current!=NULL){
        printf("%d",current->value);
        current=current->next;
    }
}

void freeList(list* Head) {
    while (Head != NULL) {
       list* temp = Head;
        Head = Head->next;
        free(temp);
    }
}

void alternate_elimation(list** head){
    list* current=*head;
    if(current==NULL||current->next==NULL)
        return;
    remove_alternate(head);
    reverse_list(head);
    alternate_elimation(head);                                                              
}

int main() {
    int n;
    scanf("%d",&n);
    
    list* head=NULL;
    for(int i=1;i<=n;i++)
        create_node(&head,i);
    
    alternate_elimation(&head);
    display(head);
    freeList(head);
    return 0;
}
