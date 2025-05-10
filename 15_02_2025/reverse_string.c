#include<stdio.h>

void reverse_string(char str[],int i){
    if(str[i]=='\0')return;
    reverse_string(str,i+1);
    printf("%c",str[i]);
}

int main(){
    char str[100];

    scanf("%[^\n]",str);
    reverse_string(str,0);
    return 0;
}