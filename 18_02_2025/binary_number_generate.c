#include<stdio.h>
void generate_binary_number(int arr[],int n,int index){
    
    if(index==n){
        for(int itr=0;itr<n;itr++)
            printf("%d ",arr[itr]);
        printf("\n");
        return;
    }
    arr[index]=0;
    generate_binary_number(arr,n,index+1);

    arr[index]=1;
    generate_binary_number(arr,n,index+1);
}

int main(){
    int n;    
    printf("Enter value of n: ");
    scanf("%d",&n);

    int arr[n];
    generate_binary_number(arr,n,0);
    
}