#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}queue;

int is_empty(queue* front){
    return front==NULL;
}

queue* create_node(int value){
    queue* new_node=malloc(sizeof(queue));
    new_node->data=value;
    new_node->next=NULL;
    return new_node;    
}

void enqueue(queue** front,queue** rear,int* size,int value){
    queue* new_node=create_node(value);
    if(*rear==NULL){
        *front=new_node;
        *rear=new_node;
     }else{
    (*rear)->next=new_node;
    *rear=new_node;
     }
    (*size)++;
}

void dequeue(queue** front,queue** rear,int* size){
    if(is_empty(*front)){
        printf("Empty\n");
        return;
    }
    queue* temp=*front;
    (*front)=(*front)->next;
    if(*front==NULL)
        {
            *rear=NULL;
        }
    free(temp);
    (*size)--;
}

int peek(queue* front){
    if(is_empty(front)){
        printf("Empty\n"); 
        return -1;
    }
    return front->data;
}

void free_queue(queue* front){
    queue* temp=front;
    while(temp!=NULL){
        queue* tofree=temp;
        temp=temp->next;
        free(tofree);
    }
}

int main(){
    queue* rear=NULL,*front=NULL;
    
    int choice=0,value,length=0;
    while(choice!=6){
        scanf("%d",&choice);
        switch(choice){
           case 1:
                scanf("%d",&value);
                enqueue(&front,&rear,&length,value);
                break;
            case 2:
                dequeue(&front,&rear,&length);
                break;
            case 3:
            printf("%d\n",peek(front));
            break;
            case 4:
            is_empty(front)?printf("True\n"):printf("False\n");
            break;
            case 5:
            printf("%d\n",length);
            break;
            case 6:
            free_queue(front);
            front=NULL;
            return 0;
        }    
    }
    return 0;
}