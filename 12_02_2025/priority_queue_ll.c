#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char name[20];
    int priority;
    struct node* next;
}node;

enum MENU{
    ENQUEUE=1,
    DEQUEUE,
    DISPLAY,
    EXIT
};

node* create(char str[],int value){
    node* new_node=malloc(sizeof(node));
    new_node->next=NULL;
    strcpy(new_node->name,str);
    new_node->priority=value;
    return new_node;
}

void enqueue(node** front, node** rear, char str[], int value){
    node* new = create(str, value);
    if (*front == NULL) {
        *front = *rear = new;
        return;
    }

    if ((*front)->priority > value || 
        ((*front)->priority == value && strcmp((*front)->name, str) > 0)) {
        new->next = *front;
        *front = new;
        return;
    }

    node* current = *front;
    while (current->next != NULL && 
          (current->next->priority < value || 
          (current->next->priority == value && strcmp(current->next->name, str) < 0))) {
        current = current->next;
    }

    new->next = current->next;
    current->next = new;

    if (current == *rear) {
        *rear = new;
    }
}

void dequeue(node** front,node** rear){
    if(*front==NULL){
        printf("Empty Queue!\n");
        return;
    }
    (*front)=(*front)->next;
}

void display(node* front){
    if(front==NULL){
        printf("Empty\n");
        return;
    }
    node* current=front;
    while(current!=NULL){
        printf("%s %d\n",current->name,current->priority);
        current=current->next;
    }
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
                printf("Enter name:");
                scanf("%s",str);
                printf("Enter value:");
                scanf("%d",&value);
                enqueue(&front,&rear,str,value);
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