#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void calcSubset(int* A, int n, int* subset, int subset_size, int index)
{
    printf("[");
    for (int i = 0; i < subset_size; i++) {
        printf("%d", subset[i]);
        if (i < subset_size - 1) {
            printf(", ");
        }
    }
    if(index==n && subset_size==1)
        printf("]");
    else
        printf("], ");

    for (int i = index; i < n; i++) {
        subset[subset_size] = A[i];
        calcSubset(A, n, subset, subset_size + 1, i + 1);
    }
}

void subsets(int* A, int n)
{
    int subset[n];
    calcSubset(A, n, subset, 0, 0);
}

int main() {
    int arr[15];
    int index=0;
    while(scanf("%d",&arr[index])==1){
        index++;
        if(getchar()=='\n')
            break;
    }

    int n=index;
    int subset[15];
    bubble_sort(arr,n);
    
    printf("[");
    subsets(arr,n);
    printf("]");
    return 0;
}
