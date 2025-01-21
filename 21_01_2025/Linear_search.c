#include<stdio.h>
#include<stdlib.h>

void Linear_search(int* arr,int key){
    int size=sizeof(arr)/sizeof(arr[0]);
    int flag=0;
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            printf("Element found at %d position\n",i);
            flag=1;
            break;
        }
    }
    if(!flag)
        printf("Element not found\n");
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

    int key;
    scanf("%d",&key);
    Linear_search(arr,key);
    return 0;
}