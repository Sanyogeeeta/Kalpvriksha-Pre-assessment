#include<stdio.h>
#define MAX 1000

int min_operations(int arr[],int length){
    int operations=0,increment;
    for(int i=1;i<length;i++){
        if(arr[i]<=arr[i-1]){
            increment=arr[i-1]-arr[i]+1;
            arr[i]+=increment;
            operations+=increment;
        }
    }
    return operations;
}

int main(){
    int array[MAX],index=0;

    printf("Input:");
    while(getchar()!='[');
    while(scanf("%d",&array[index])==1){
        index++;
        if(getchar()==']')break;
    }

    printf("Output:%d",min_operations(array,index));
    return 0;
}