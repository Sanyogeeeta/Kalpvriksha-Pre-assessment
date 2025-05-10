#include<stdio.h>
#define MAX 10

void merge(int arr[],int l,int mid,int r){
    int temp[MAX];
    int i=l;
    int j=mid;
    int k=0;


    while(i<mid&& j<r){
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<mid)
        temp[k++]=arr[i++];
    while(j<r)
        temp[k++]=arr[j++];

    for(int i=l;i<r;i++){
        arr[i]=temp[i-l];
    }
}

void display(int arr[],int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
}
void merge_sort(int arr[],int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    int arr[MAX];
    int index=0;

    while(scanf("%d",&arr[index])==1){
        index++;
        if(getchar()=='\n')break;
    }

    display(arr,index);
    merge_sort(arr,0,index);
    display(arr,index);
}