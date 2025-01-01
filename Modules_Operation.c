#include<stdio.h>
long long unsigned Modular_Expression(unsigned long base,unsigned long exponent,unsigned long mod){
    long long unsigned result=1;
    base=base%mod;
    while(exponent>0){
        if(exponent%2==1)
            result=(result*base)%mod;
        base=(base*base)%mod;
        exponent=exponent/2;
    }
    return result;
}
int main(){
    long unsigned B,N,M;
    printf("Base(B):");
    scanf("%lu",&B);
    printf("Exponent(N):");
    scanf("%lu",&N);
    printf("Modulus(M):");
    scanf("%lu",&M);
    long long unsigned result=Modular_Expression(B,N,M);
    printf("Result:%llu\n",result);
}