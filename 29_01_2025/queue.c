#include<stdio.h>
#include<stdlib.h>

void enqueue(int* queue,int* front,int* rear,int value,int capacity){
    if(*rear==capacity-1){
        printf("FULL");
        return;
    } 
    if(*front==-1)
        *(front)=0;
    (*rear)++;
    queue[*rear]=value;
}

void dequeue(int* front,int* rear){
    if(*front==-1||*front>*rear){
        *front=*rear=-1;
        printf("Empty\n");
        return;
    }
    (*front)++;
}


int main(){

    int choice=0,rear=-1,length,front=-1;
    int value;

    scanf("%d",&length);
    int* queue=malloc(sizeof(int)*length);
    while(choice!=3){
        scanf("%d",&choice);
        switch(choice){
            case 1:
                scanf("%d",&value);
                enqueue(queue,&front,&rear,value,length);
                break;
            case 2:
                dequeue(&front,&rear);
                break;
            case 3:
                return 0;
        }
    }
    return 0;
}