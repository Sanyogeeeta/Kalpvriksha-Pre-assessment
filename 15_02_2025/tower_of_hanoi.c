#include<stdio.h>

void tower_of_hanoi(int n,char A,char B,char C){
    if(n==1){
        printf("%d move from %c to %c\n",n,A,B);
        return;
    }
    tower_of_hanoi(n-1,A,C,B);
    printf("%d move from %c to %c\n",n,A,B);
    tower_of_hanoi(n-1,C,B,A);
}

int main(){
    int n;
    char A='A',B='B',C='C';
    scanf("%d",&n);
    tower_of_hanoi(n,A,B,C);;
    return 0;
}