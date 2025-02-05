#include<stdio.h>
#define MAX 10

int is_full(int top){
    return top==MAX-1;
}

int is_empty(int top){
    return top==-1;
}

int pop(int stack[],int* top){
    if(is_empty(*top))return -1;
    return stack[(*top)--];
}

void push(int stack[],int *top,int value){
    if(is_full(*top))return;
    stack[++(*top)]=value;
}

void display(int stack[],int top){
    for(int i=0;i<=top;i++)
        printf("%d ",stack[i]);
}

void sort_stack(int stack[],int* top){
    int temp[MAX],top1=-1,num;
    
    while(!is_empty(*top)){
        int num=pop(stack,top);  

        while(!is_empty(top1) && temp[top1] < num){
            push(stack,top,temp[top1]);
           top1--;
        }
        push(temp,&top1,num);
    }
    
    while(!is_empty(top1)){
        push(stack,top,temp[top1]);
        top1--;
    }
}

int main(){
    int stack[MAX];
    int top=-1;
    push(stack,&top,5);
    push(stack,&top,6);
    push(stack,&top,2);
    push(stack,&top,1);
    push(stack,&top,4);
    push(stack,&top,3);
    display(stack,top);
    sort_stack(stack,&top);
    display(stack,top);
}