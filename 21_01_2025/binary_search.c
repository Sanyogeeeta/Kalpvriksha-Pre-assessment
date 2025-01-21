#include<stdio.h>
#include<stdlib.h>

int binary_search(int* arr,int low,int high,int key){
    if(low<=high){
        int middle=(low+high)/2;
        if(arr[middle]==key){
            return middle;
        }
        else if(arr[middle]<key)
            return binary_search(arr,middle+1,high,key);
        else
            return binary_search(arr,low,middle-1,key);    
    }
    return -1;
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

    int key,low,high;
    low=0;
    high=index-1;

    scanf("%d",&key);
    int result=binary_search(arr,low,high,key);
    if(result!=-1)
        printf("Element found at position %d\n",result);
    else
        printf("Element not found\n");
    return 0;
}