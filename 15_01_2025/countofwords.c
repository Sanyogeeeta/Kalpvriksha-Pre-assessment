#include<stdio.h>
#include<string.h>

int main(){
    char str[100];
    char word[25];
    int count=0;
    fgets(str,sizeof(str),stdin);
    char* ptr=str;
    while(*ptr){
    while(*ptr==' ')
    ptr++;
    if(sscanf(ptr,"%s",word)==1){        
        ptr+=(strlen(word));
        count+=1;
    }else
        break;
}

    printf("%d",count);
}