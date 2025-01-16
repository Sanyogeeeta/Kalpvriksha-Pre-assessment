#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(){
    char str[100];
    char* ptr=str;
    int dot_count=0;

    fgets(str,sizeof(str),stdin);
    str[strcspn(str, "\n")] = '\0';
    int num,flag=0;

    while(*ptr){
        while(*ptr==' ')
            ptr++;
        if(isdigit(*ptr)){
            sscanf(ptr,"%d",&num);
            while(isdigit(*ptr))
                ptr++;
            if(num<0 || num>255){
                flag=1;
                break;
            }
        }
        else if(*ptr=='.'){
            dot_count++;
            ptr++;
        }
        else{
            flag=0;
            break;
        }

    }

    if(dot_count==3 && flag==0)
        printf("true");
    else
        printf("false");
    return 0;
}