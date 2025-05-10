#include<stdio.h>
#include<stdlib.h>

int* insertion(int* arr,int* size,int index,int value){
    if(index<=(*size)){
        *size=(*size)*2;
        arr=realloc(arr,(sizeof(int)*(*size)));
    }
    arr[index]=value;
    return arr;
}

void display(int* arr,int index){
    for(int i=0;i<index;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){

    int* arr=malloc(sizeof(int));
    int size=1;

    int n,value;
    int choice=0,index=0;
    while(choice!=2){
        scanf("%d",&choice);
    switch(choice){
        case 1:
        scanf("%d",&value);
        arr=insertion(arr,&size,index,value);
        index++;
        break;
        case 2:
        display(arr,index);
        break;
        case 3:
        return 0;
    }
    }
    return 0;
}