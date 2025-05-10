#include<stdio.h>
#include<stdlib.h>

void push(int* stack,int* top,int value,int capacity){
    if(*top>=capacity-1){
        printf("Full\n");
        return;
    }
    (*top)++;
    stack[*top]=value;
}

void pop(int* top){
    if(*top==-1){
        printf("Empty\n");
        return;
    }
    (*top)--;
}


int main(){

    int choice=0,top=-1,length;
    int value;

    scanf("%d",&length);
    int* stack=malloc(sizeof(int)*length);
    while(choice!=3){
        scanf("%d",&choice);
        switch(choice){
            case 1:
                scanf("%d",&value);
                push(stack,&top,value,length);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                return 0;
        }
    }
    return 0;
}