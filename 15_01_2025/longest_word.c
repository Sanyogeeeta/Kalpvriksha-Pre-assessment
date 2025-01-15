#include<stdio.h>
#include<string.h>

int main(){
    char str[100];
    fgets(str,sizeof(str),stdin);
    int len=strlen(str);
    char* ptr=str;
    char word[25],long_word[25];
    strcpy(long_word,"");
    while(*ptr){
        while(*ptr==' ')
        ptr++;
        if(sscanf(ptr,"%s",word)){
            if(strlen(word)>strlen(long_word))
                strcpy(long_word,word);
        ptr+=strlen(long_word);
        }
    }
    printf("%s",long_word);
}
