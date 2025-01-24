#include <stdio.h>
#include <stdlib.h>

void calcSubset(int* arr, int n, int* subset, int size, int index,int k)
{
    if(size==k){
        for(int i=0;i<size;i++)
            printf("%d ",subset[i]);
        printf("\n");   
        return;
    }
    for (int i = index; i < n; i++) {
        subset[size]=arr[i];
        calcSubset(arr,n,subset,size+1,i+1,k);
    }
}

int main() {
    int n,k;
    scanf("%d %d",&k,&n);

    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    int subset[k];

    calcSubset(arr,n,subset,0,0,k);
    return 0;
}
