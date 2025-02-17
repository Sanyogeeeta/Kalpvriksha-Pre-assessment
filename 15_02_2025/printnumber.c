#include<stdio.h>

void recursive_print(int n){
    if(n==0)return;
    recursive_print(n-1);
    printf("%d ",n);
}

int main(){
    int n;
    scanf("%d",&n);
    recursive_print(n);
}