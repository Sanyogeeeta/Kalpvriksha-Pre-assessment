#include<stdio.h>
#include<string.h>

void sort(char* str){
    int len=strlen(str);
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len;j++){
            if(str[i]>str[j]){
                char temp=str[i];
                str[i]=str[j];
                str[j]=temp;
            }
        }
    }
}

int is_anagram(char *str1,char *str2){
    int flag=0;
    sort(str1);
    sort(str2);
    if(strcmp(str1,str2)==0)
        flag=1;
    return flag;
}

int is_rotation(char* str1,char* str2){
    int flag=0;
    int len=strlen(str1);
    for(int i=0;i<len-1;i++){
        if(str1[i]==str2[i]) continue;
        else{
           char temp=str2[0];
           for(int j=0;j<len-1;j++){
            str2[j]=str2[j+1];
           }
           str2[len-2]=temp;
        }
        if(strcmp(str1,str2)==0){
            flag=1;
            break;
        }
    }
    return flag;
}

int main(){
    char str1[200],str2[200];
    fgets(str1,sizeof(str1),stdin);
    fgets(str2,sizeof(str2),stdin);
    if(strlen(str1)==strlen(str2)){
    if(is_rotation(str1,str2))
        printf("rotation");
    if(is_anagram(str1,str2))
        printf("anagram");
    }
    else
    printf("None");
    
}