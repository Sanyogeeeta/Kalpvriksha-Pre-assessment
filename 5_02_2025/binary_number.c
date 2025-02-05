#include<stdio.h>
#define MAX 100

int isEmpty(int front){
    return front==-1;
}

int Full(int rear){
    return rear==MAX-1;
}

void enqueue(char arr[],int* front,int* rear,char value){
    if(*front==-1)
        *front=0;
    arr[++(*rear)]=value;
}

void dequeue(char arr[],int* front,int* rear){
    if(isEmpty(*front)){
        printf("Empty!");
        return;
    }
    if((*front)==(*rear))
        (*front)=(*rear)=-1;
    else arr[(*front)++];
}

void generate_binary(char arr[],int*front,int* rear,int n){
    char bin[MAX];
    int index=0;
    
    int num=n;
    while(num!=0){
        bin[index++]=(num%2)+'0';
        num/=2;
    }
    for(int i=index-1;i>=0;i--)
        enqueue(arr,front,rear,bin[i]);    
    
}

void display(char arr[],int front,int rear){
    for(int i=front;i<=rear;i++){
        printf("%c ",arr[i]);
    }
}

int main(){
    int n,front=-1,rear=-1;
    char arr[MAX];
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        generate_binary(arr,&front,&rear,i);
        display(arr,front,rear);
        if(i!=n)printf(",");
        while(!isEmpty(front))dequeue(arr,&front,&rear);
    }
    printf("\n");
}
