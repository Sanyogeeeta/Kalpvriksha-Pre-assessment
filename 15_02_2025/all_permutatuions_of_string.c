#include<stdio.h>
#include<string.h>

void swap(char* c1,char*c2){
    char temp=*c1;
    *c1=*c2;
    *c2=temp;
}

void string_permutations(char str[],int l,int r){
    if(l==r){
        printf("%s\n",str);
        return;
    }
    for(int i=l;i<=r;i++){
        swap(&str[l],&str[i]);
        string_permutations(str,l+1,r);
        swap(&str[l],&str[i]);
    }    
}

int main(){
    char str[200];
    scanf("%s",str);
    string_permutations(str,0,strlen(str)-1);
    return 0;
}