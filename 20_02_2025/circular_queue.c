#include<stdio.h>
#define MAX 5

enum MENU{
    ENQUEUE=1,
    DEQUEUE,
    DISPLAY,
    EXIT
};

void enqueue(int* q,int* front,int* rear,int value){
    if((*rear+1)%MAX==*front){
        printf("Queue is Full\n");
        return;
    }
    (*rear)=((*rear)+1)%MAX;
    if((*front)==-1)
        (*front)=0;
    q[*rear]=value;
}

void dequeue(int* q,int* front,int* rear){
    if((*front)==-1){
        printf("Queue is Empty\n");
        return;
    }
    if((*front)==(*rear)){
        (*front)=(*rear)=-1;
        return;
    }
    (*front)=((*front)+1)%MAX;
}

void display(int queue[],int front,int rear){
    if(front==-1){
        printf("Empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i != (rear + 1) % MAX; i = (i + 1) % MAX) {
        printf("%d ", queue[i]);
    }
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