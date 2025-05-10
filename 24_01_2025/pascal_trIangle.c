#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int* arr;
    struct node* next;
}list;


void create_node(list** head,int n){
    list* new_node=malloc(sizeof(list));
    new_node->next=NULL;
    new_node->arr=malloc(sizeof(int)*n);
    if(*head==NULL){
        *head=new_node;
        return;
    }
    list* current=*head;
    while(current->next!=NULL)
        current=current->next;
    current->next=new_node;
}

void pascal_triangle(list** head,int n)
{
    list* current=NULL,*prev=NULL;
    for(int i=0;i<n;i++){
        create_node(head,i+1);
        current = *head;
        while (current->next != NULL)
            current = current->next;

        for(int j=0;j<=i;j++){
            if(i==0){                
                current->arr[j]=1;
            }
            else{
                if(j==0||j==i)
                    current->arr[j]=1;
                else
                    current->arr[j]=prev->arr[j-1]+prev->arr[j];
            }
        }
        prev=current;
    }    
}

void freeList(list* Head) {
    while (Head != NULL) {
       list* temp = Head;
        Head = Head->next;
        free(temp->arr);
        free(temp);
    }
}

void display(list* head,int n){
    list* current=head;
    while(current->next!=NULL){
        current=current->next;
    }

    for(int i=0;i<n;i++){
        if(i==n-1)
            printf("%d\n",current->arr[i]);
        else
            printf("%d ",current->arr[i]);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    
    list* head=NULL;
    
    pascal_triangle(&head,n);
    display(head,n);
    freeList(head);
    return 0;
}
