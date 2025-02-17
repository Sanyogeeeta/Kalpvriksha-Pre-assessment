#include<stdio.h>
#include<string.h>

int recursive_atoi(char* str,int n){
    if(n==1)
        return str[0]-'0';
    return 10*recursive_atoi(str,n-1)+str[n-1]-'0';
}

int main(){
    char number[6];
    scanf("%s",number);

    int num=recursive_atoi(number,strlen(number));
    printf("%d",num);
    return 0;
}