#include<string.h>
#include<stdio.h>

int main(){
    char str[200],result[200];
    fgets(str,sizeof(str),stdin);

    int len=strlen(str);
    int i=0,res_len=0;
    
    while(i<len){
        char temp=str[i];
        int count=1;
        while(str[i]==str[i+1]){
            count++;
            i++;
        }
        result[res_len++]=temp;
        if(count>1)
            result[res_len++]=count+'0';
        i++;
    }
    printf("%s\n",result);

    return 0;
}