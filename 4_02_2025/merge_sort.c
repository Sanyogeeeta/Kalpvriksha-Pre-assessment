#include<stdio.h>

void merge(int arr[],int l,int mid,int r){
    int l_len=mid-l+1,r_len=r-mid+1;
    int L[l_len],R[r_len];
    for(int i=0;i<mid;i++)L[i]=arr[l+i];
    for(int j=0;j<r-mid+1;j++)R[j]=arr[mid+j];

    int i=0,j=0,k=l;
    while(i<l_len&& j<r_len){
        if(L[i]<R[j])arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }

    while(i<l_len){
        arr[k++]=L[i++];
    }
    while(j<r_len){
        arr[k++]=R[i++];
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

void display(int arr[],int len){
    for(int i=0;i<len;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main(){

    int n;
    scanf("%d",&n);

    int arr[n];
    int index=0;
    while(scanf("%d",&arr[index++])==1);
    merge_sort(arr,0,index-1);
    display(arr,index);
    return 1;
}