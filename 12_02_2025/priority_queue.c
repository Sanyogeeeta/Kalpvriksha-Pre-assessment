#include<stdio.h>
#define MAX 100

enum MENU{
ENQUEUE=1,
DEQUEUE,
DISPLAY,
EXIT
};

void enqueue(int* queue,int* front,int* rear,int value){
    int i=*front;
    if((*front)==-1)
        (*front)++;
    while(i<=(*rear)&&queue[i]<value){
        i++;
    }
    for(int j=(*rear);j>=i;j--){
        queue[j+1]=queue[j];
    }
    queue[i]=value;
    (*rear)++;
}

void dequeue(int* queue,int* front,int* rear){
    if((*front)==-1){
        printf("Empty Queue!\n");
    }
    if((*front)==(*rear)){
        (*front)=-1;
        (*rear)=-1;
        return;
    }
    (*front)++;
}

void display(int queue[],int front,int rear){
    if(front==-1){
        printf("Empty\n");
        return;
    }
    for(int i=front;i<=rear;i++)
        printf("%d ",queue[i]);
    printf("\n");
}

int main(){
    int queue[MAX];
    int choice=0,front=-1,rear=-1,value;

    while(choice!=4){
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case ENQUEUE:
                printf("Enter value:");
                scanf("%d",&value);
                enqueue(queue,&front,&rear,value);
                break;
            case DEQUEUE:
                dequeue(queue,&front,&rear);
                break;
            case DISPLAY:
                display(queue,front,rear);
                break;
            case EXIT:
            printf("Exit program");
            return 0;
        }
    }
    return 0;
}