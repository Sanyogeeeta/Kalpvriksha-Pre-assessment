#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 128

typedef struct node{
    char name[20];
    long long int phone_no;
}node;


int hash_function(char str[20]){
    int index=0;
    for(int i=0;i<strlen(str);i++){
        index+=str[i];
    }
    return index%MAX;
}

node create(node hashmap[],char str[],long long int number){
    int index=hash_function(str);
    strcpy(hashmap[index].name,str);
    hashmap[index].phone_no=number;
}

int main(){
    long long int number;
    int n;
    char str[20];
    node hashmap[MAX]={0};
    scanf("%d",&n);
    while((--n)>=0){
        scanf("%s %lld",str,&number);
        create(hashmap,str,number);
    }

    for(int i=0;i<MAX;i++){
        if(strcmp(hashmap[i].name,"\0")==0)continue;
        printf("%s %lld\n",hashmap[i].name,hashmap[i].phone_no);
    }
    return 0;
}