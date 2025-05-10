#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

void swap(char* x,char* y){
    char temp=*x;
    *x=*y;
    *y=temp;
}

void reverse(char str[]){
    int len=strlen(str)-1;
    for(int i=0;i<len/2;i++){
        if(str[i]=='('||str[i]==')')continue;
        swap(&str[i],&str[len-1]);
    }
}

int isOperator(char c){
    return (c=='+'||c=='-'||c=='*'||c=='/');
}

int pop(char s[],int* top){
    if(*top!=-1)
        return s[(*top)--];
    return '\0';
}

void push(char s[],int* top,char value){
    s[++(*top)]=value;
}
void prefix_infix(char str[],char s[],char res[],int* top){
    int len=strlen(str);
    int index=0;
    for(int i=0;i<len;i++){
        if(isalnum(str[i]))res[index++]=str[i];
        else if(isOperator(str[i])){
        while(*top!=-1&& isOperator(s[*top])&&isOperator(str[i])){
             res[index++]=pop(s,top);            
        }
        push(s,top,str[i]);
        }
    }
    while (*top != -1) {
        res[index++] = pop(s, top);
    }
    res[index] = '\0'; 
}

int main(){
    char str[MAX],res[MAX];
    char s[MAX];
    int top=-1;
    int index=0;

    scanf("%s",str);
    prefix_infix(str,s,res,&top);
    printf("%s",res);
    return 0;
}