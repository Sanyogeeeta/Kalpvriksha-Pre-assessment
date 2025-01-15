#include<stdio.h>
#include<string.h>

int duplicateremove(char str[],int i,int* len){
    int flag=0;
    for(int index=i-1;index>=0;index--){
        if(str[index]==str[i]){
            flag=1;
            break;
        }
    }
    if(flag==1){
        for(int j=i;j<*len-1;j++){
            str[j]=str[j+1];
        }
        (*len)-=1;
        str[(*len)]='\0';
    }
    return flag;
}

int main(){
    char str[100];
   fgets(str,sizeof(str),stdin);
    int len=strlen(str);
    //printf("%s\n",str);
    for(int i=0;i<len;i++){
        int res=duplicateremove(str,i,&len);
        //printf("%s\n",str);
        if(res)
            i--;        
    }
    printf("%s\n",str);

}