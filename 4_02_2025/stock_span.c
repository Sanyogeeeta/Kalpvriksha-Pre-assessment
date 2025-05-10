#include<stdio.h>
#define MAX 100

int stock_span(int s[],int n){
    int count=0;
    int prev=-1;
    for(int i=0;i<n;i++){
        if(i==0||s[i]<s[i-1]){
            count=1;
        }
        else{
            count=1;
            for(int j=0;j<i;j++)
            if(s[i]>=s[j])count+=1;
        }
        printf("%d ",count);
    }
}

int main(){
    int value;
    int s[MAX],index=0;
    getchar();
    while(scanf("%d",&value)==1){
        s[index++]=value;
        if(getchar()==']')break;
    }

    printf("[");
    stock_span(s,index);
    printf("]");
    return 0;
}