#include<stdio.h>

int gcd(int a,int b){
    if(b==0)return a;
    gcd(b,a%b);
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(a<b){
        int temp=a;
        a=b;
        b=temp;
    }
    printf("%d",gcd(a,b));
    return 0;
}