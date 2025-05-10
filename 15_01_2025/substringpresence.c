#include<stdio.h>
#include<string.h>

int substring_index(char str[],char substr[]){
    int index=0,flag=0;
    char*ptr=str;
    char temp[25];
    while(*ptr){
        while(*ptr==' '){
        ptr++;
        index++;
        }
        if(sscanf(ptr,"%s",temp)){
            if(strstr(temp,substr)!=NULL){
                flag=1;
                break;
            }
            index+=strlen(temp);
            ptr+=strlen(temp);
        }
    }
    if(flag==0)
    index=-1;
    return index;
}
int main(){
    char str[100],substr[25];
    fgets(str,sizeof(str),stdin);
    fgets(substr,sizeof(substr),stdin);
    int substr_len=strlen(substr)-1;
    substr[substr_len]='\0';
    int index=substring_index(str,substr);
    if(index!=-1)
        printf("%d\n",index);
    return 0;
}