#include<stdio.h>
#include<limits.h>

struct node{
    int value;
    int index;
};

struct node list[100];

int position=0;
int head=-1;
void insertAtEnd(int value,int next){
    list[position].value=value;
    list[position].index=-1;
    if(head==-1){
        head=position;
    }
    list[position].index=next;
    position=next;
}

void display(){
    int current=head; 
    if(head==-1){
        printf("Empty\n");
        return;
    }
    while(current!=-1){
        printf("%d",list[current].value);
        current=list[current].index;
    }    
}

int main(){
    insertAtEnd(1,3);
    insertAtEnd(2,6);
    insertAtEnd(3,-1);
    display();
    return 0;
}