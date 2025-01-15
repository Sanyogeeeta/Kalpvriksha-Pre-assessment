#include<stdio.h>
#include<string.h>

int main(){
    char str[100];
    char instance;

    fgets(str,sizeof(str),stdin);
    scanf("%c",&instance);
    
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]==instance){
            for(int j=i;j<len-1;j++){
                str[j]=str[j+1];
            }
            str[len-1]='\0';
            len--;
            i--;
        }
    }

    printf("%s\n",str);
    return 0;
}