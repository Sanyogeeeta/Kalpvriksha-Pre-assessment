#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int is_empty(int front){
    return front==-1;
}

void enqueue(int* queue,int* front,int* rear,int* length,int value){
    if(*rear==MAX-1){
        printf("Queue is Full");
        return;
    } 
    if(*front==-1)
        *(front)=0;
    (*rear)++;
    queue[*rear]=value;
    (*length)++;
}

void dequeue(int* front,int* rear,int* length){
    if(is_empty(*front)||(*front>(*rear))){
        printf("Queue is Empty\n");
        return;
    }
    (*front)++;
    (*length)--;
    if (*front > *rear) {
        *front = *rear = -1;
    }
}

int peek(int* queue,int front){
    if(is_empty(front)){
        printf("Queue is Empty\n");
	    return -1;
    }
    return queue[front];
}

int main(){
    int choice=0,rear=-1,length=0,front=-1;
    int value;

    int* queue=malloc(sizeof(int)*MAX);
    while(choice!=6){
        scanf("%d",&choice);
        switch(choice){
           case 1:
                scanf("%d",&value);
                enqueue(queue,&front,&rear,&length,value);
                break;
            case 2:
                dequeue(&front,&rear,&length);
                break;
            case 3:
            printf("%d\n",peek(queue,front));
            break;
            case 4:
            is_empty(front)?printf("True\n"):printf("False\n");
            break;
            case 5:
            printf("%d\n",length);
            break;
            case 6:
            free(queue);
            return 0;
        }    
    }
    return 0;
}