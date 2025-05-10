#include<stdio.h>
#define MAX 10

void swap(int* x,int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void heapify(int arr[],int i,int n)
{
    int large=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[i]<arr[left])
        large=left;
    if(right<n && arr[large]<arr[right])
        large=right;
    if(large!=i){
        swap(&arr[large],&arr[i]);
        heapify(arr,large,n);
    }
}

void heap_sort(int arr[],int n){

    for(int j=n/2;j>=0;j--)
        heapify(arr,j,n);

    int length=n;
    for(int i=n-1;i>=0;i--){
        swap(&arr[i],&arr[0]);
        heapify(arr,0,i);
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++)printf("%d ",arr[i]);
    printf("\n");
}

int main(){
    int arr[MAX]={0};
    int n;
    scanf("%d",&n);
    int i=0,value;
    while(i<n){
        scanf("%d",&arr[i]);
        i++;
    }
    display(arr,n);

    heap_sort(arr,n);
    display(arr,n);
    return 0;
}