#include<stdio.h>
#define MAX 1000

void push(int* bookmark,int* top,int value){
    if((*top)==MAX-1){
        printf("Stack is FULl\n");
        return;
    }
    bookmark[++(*top)]=value;
}

void pop(int* bookmark,int* top){
    if((*top)==-1){
        printf("No bookmarks available\n");
        return;
    }
    printf("recent bookmark %d deleted\n",bookmark[(*top)--]);
}

void book_mark(int* bookmark,int* top,int value){
    push(bookmark,top,value);
}

void delete(int* bookmark,int* top){
    pop(bookmark,top);
}

void sort(int* temp,int top){
    if(top<=0)
        return;
    int temp2[top+1],top2=-1;  

    while(top>=0){
        int current = temp[top--];
        
        while(top2>=0 && temp2[top2]>current){
            temp[++top]=temp2[top2--];
        }
        temp2[++top2]=current;
    }
    while (top2 >= 0) {
        temp[++top] = temp2[top2--];
    }
}

void display(int* bookmark,int top){
    if(top==-1){
        printf("No bookmarks available\n");
        return;
    }
    for(int index=top;index>=0;index--){
        printf("%d ",bookmark[index]);
    }
    printf("\n");
}

void list(int* bookmark,int top){
    if(top==-1){
        printf("No bookmarks available\n");
        return;
    }
    int temp[MAX],top1=-1;
    for(int index=0;index<=top;index++){
        temp[++top1]=bookmark[index];
    }
    sort(temp,top1);
    display(temp,top);    
}

int main(){
    int bookmark[MAX];
    int choice=0;
    int page,top=-1;

    while(choice!=4){
        scanf("%d",&choice);
        switch(choice){
            case 1:
            scanf("%d",&page);
            book_mark(bookmark,&top,page);
            break;
            case 2:
            delete(bookmark,&top);
            break;
            case 3:
            list(bookmark,top);
            break;
            case 4:
            return 0;
            default:
            printf("Invalid\n");
        }
    }
    return 0;
}