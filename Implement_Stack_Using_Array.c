#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct stack{
    int* arr;
    int capacity;
    int top;
    int size;
}stack;

int is_full(int top,int capacity){
    return top==capacity-1;
}

int is_empty(int top){
    return top==-1;
}

void pop(stack *s){
    if(is_empty(s->top)){
        printf("Stack is Empty\n");
        return;
    }
    s->top-=1;
    s->size-=1;
}

int peek(stack* s){
    if(is_empty(s->top)){
        printf("Stack is Empty\n");
	return -1;
    }
    return s->arr[s->top];
}

void push(stack* s,int value){
    if(is_full(s->top,s->capacity)){
        printf("Stack is Full!");
        return;
    }
    s->top+=1;
    s->arr[s->top]=value;
    s->size+=1;
}

int main(){
    stack s;
    s.top=-1;
    scanf("%d",&s.capacity);

    s.arr=malloc(sizeof(int)*s.capacity);
    int choice=0,value;
    while(choice!=6){
        scanf("%d",&choice);
        switch(choice){
            case 1:
            scanf("%d",&value);
            push(&s,value);
            break;
            case 2:
            pop(&s);
            break;
            case 3:
            printf("%d",peek(&s));
            break;
            case 4:
            is_empty(s.top)?printf("True\n"):printf("False\n");
            break;
            case 5:
            printf("%d\n",s.size);
            break;
            case 6:
            free(s.arr);
            return 0;
        }    
    }
    return 0;
}
