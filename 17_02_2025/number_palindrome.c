#include<stdio.h>

int palindrome_num(int number,int reverse){
    if(number==0)return reverse;
    return palindrome_num(number/10,10*reverse+number%10);
}

int main(){
    int number;
    scanf("%d",&number);

    int num=palindrome_num(number,0);
    printf("%d\n",num);
    (num==number)?printf("palindrome\n"):printf("Not a palindrome\n");
    return 0;
}