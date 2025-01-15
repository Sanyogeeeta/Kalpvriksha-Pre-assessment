#include<stdio.h>
#include<string.h>

int str_to_int(char *str){
    int num=0;
    int sign=1;
    for(int i=0;i<strlen(str)-1;i++){
        if(str[i]=='-'){
            sign*=-1;
        }
        else
        num=num*10+str[i]-'0';
    }
    return num*sign;
}

int main(){
    char str[100];

    fgets(str,sizeof(str),stdin);
    int num=str_to_int(str);

    printf("%d\n",num);
    return 0;
}