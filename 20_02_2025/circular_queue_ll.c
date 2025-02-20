#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int value;
    struct node* next;
}node;

enum MENU{
    ENQUEUE=1,
    DEQUEUE,
    DISPLAY,
    EXIT
};

node* create_node(int value){
    node* new_node=malloc(sizeof(node));
    new_node->next=new_node;
    new_node->value=value;
    return new_node;
}

void enqueue(node** front,node** rear,int value){
    node* new_node=create_node(value);
   if(*front==NULL){
        (*front)=(*rear)=new_node;
        return;
   }
   new_node->next=(*front);
   (*rear)->next=new_node;
   (*rear)=new_node;
}

void dequeue(node** front,node** rear){
    if((*front)==NULL){
        printf("Empty\n");
        return;
    }
    if((*front)->next==(*front)){
        (*front)=NULL;
        return;
    }
    (*rear)->next=(*front)->next;
    node* temp=(*front);
    (*front)=(*front)->next;
    free(temp);
}
 
void display(node* front){
    node* current=front;
    if(front==NULL){
        printf("Empty\n");
        return;
    }
    while(current->next!=front){
        printf("%d ",current->value);
        current=current->next;
    }
    printf("%d\n",current->value);
}

int main(){
    node* front=NULL,*rear=NULL;
    int choice=0,value;
    char str[20];

    while(choice!=4){
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case ENQUEUE:
                printf("Enter value:");
                scanf("%d",&value);
                enqueue(&front,&rear,value);
                break;
            case DEQUEUE:
                dequeue(&front,&rear);
                break;
            case DISPLAY:
                display(front);
                break;
            case EXIT:
            printf("Exit program");
            return 0;
        }
    
    }
    return 0;
}