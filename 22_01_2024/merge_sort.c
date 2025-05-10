#include<stdio.h>

void merge(int arr[],int l,int mid,int r){
    int i,j,k;
    int nl=mid-l+1;
    int nr=r-mid;
    int L[nl],R[nr];
    for(i=0;i<nl;i++){
        L[i]=arr[l+i];
    }

    for(i=0;i<nr;i++){
        R[i]=arr[mid+i+1];
    }

    i=0;
    j=0;
    k=l;
    while(i<nl && j<nr){
        if(L[i]<R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }
    while(i<nl){
        arr[k++]=L[i++];
    }
    while(j<nr){
        arr[k++]=R[j++];
    }
}

void merge_sort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main(){
    int arr[100];
    int index=0;
    while(scanf("%d",&arr[index])==1){
        index++;
        char ch=getchar();
        if(ch=='\n') break;
    }

    for(int i=0;i<index;i++){
        printf("%d ",arr[i]);
    }

    int low=0,high=index-1;
    merge_sort(arr,low,high);
    for(int i=0;i<index;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}