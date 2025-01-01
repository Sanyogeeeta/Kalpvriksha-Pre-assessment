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
    long B,N,M;
    printf("Base(B):");
    scanf("%ld",&B);
    printf("Exponent(N):");
    scanf("%ld",&N);
    printf("Modulus(M):");
    scanf("%ld",&M);
    if(N<0 || M<=1)
        printf("Enter valid Input(M>1 and N>=0)\n");
    else
    {   
        long unsigned base,exponent,mod;
        base=(unsigned long)B;
        exponent=(unsigned long)N;
        mod=(unsigned long)M;
        long long unsigned result=Modular_Expression(base,exponent,mod);
        printf("Result:%llu\n",result);
    }
}