#include<stdio.h>
#include<stdlib.h>

void traversal(int arr[],int length)
{
    for(int i=0;i<length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void swap(int *x,int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int* arr,int l,int r){
    //naive partition
    // int pivot=arr[r];
    // int temp[r-l+1],index=0,p=r;

    // for(int i=l;i<r;i++){
    //     if(arr[i]<pivot)
    //         temp[index++]=arr[i];
    // }
    // p=index;
    // temp[index++]=pivot;
    // for(int i=l;i<r;i++){
    //     if(arr[i]>pivot)
    //         temp[index++]=arr[i];
    // }
    
    // for(int i=l;i<=r;i++){
    //     arr[i]=temp[i-l];
    // }
    // return index-1;

    //lomuto partition
    int i=l-1;
    int pivot=arr[r];
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;    
}

void quick_sort(int* arr,int l,int r){
    if(l<r){
        int j=partition(arr,l,r);
        quick_sort(arr,l,j-1);
        quick_sort(arr,j+1,r);
    }
}

int main(){
    int arr[100];
    int index=0,value;

    while(scanf("%d",&value)==1){
        arr[index++]=value;
        if(getchar()=='\n')break;
    }

    traversal(arr,index);
    int l=0,r=index-1;
    quick_sort(arr,l,r);
    traversal(arr,index);
    return 0;
}