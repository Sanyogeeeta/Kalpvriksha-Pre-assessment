#include<stdio.h>
#include<stdlib.h>

int search_range(int* res,int* arr,int size,int start,int end){    
    int index=0;
    for(int i=0;i<size;i++){
        if(arr[i]>=start && arr[i]<=end){
           res[index++]=arr[i];
        }
    }
    return index;
}

int main()
{
    int* arr;
    int n,index=0;
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);

    while(scanf("%d",&arr[index])==1){
        if(getchar()=='\n') break;
        index++;
    }

    int start,end;
    scanf("%d %d",&start,&end);
    int result[100];
    int length=search_range(result,arr,index,start,end);
    for(int i=0;i<length;i++){
        printf("%d ",result[i]);
    }
    return 0;
}