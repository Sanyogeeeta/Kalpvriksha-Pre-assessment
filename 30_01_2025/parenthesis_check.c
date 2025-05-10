#include<stdio.h>
#include<stdlib.h>

int isOpenBracket(char c){
    return (c=='['||c=='{'||c=='(');
}

int isCloseBracket(char c){
    return (c==']'||c=='}'||c==')');
}

char pop(char* stack,int* top){
    if(*top==-1)
        return '!';
    return stack[(*top)--];
}

void push(char* stack,int* top,char c){
    (*top)++;
    stack[(*top)]=c;
}

int isMatchBracket(char b1,char b2){
    return ((b1==']'&& b2=='[')||(b1==')' && b2=='(')||(b1=='}' && b2=='{'));
}

int isBalanced(char* stack,char *ptr,int* top){
    char temp;
    int result=1;
    while(*ptr!='\0'){
        if(isOpenBracket(*ptr)){
            push(stack,top,*ptr);
        }
        else if(isCloseBracket(*ptr)){
            if (*top == -1) {
                result = 0;
                break;
            }
            temp=pop(stack,top);
            if (!isMatchBracket(*ptr, temp))
            {
                result=0;
                break;
            }
        }
        ptr++;
    }
    if(*top!=-1)result= 0;
    return result;
}
int main(){
    char stack[100];
    int top=-1;
    char str[100];
    scanf("%s",str);

    char* ptr=str;
    int result=1;
    result=isBalanced(stack,ptr,&top);
    if(result==1)
        printf("Balanced\n");
    
    else printf("Not Balanced\n");
    return 0;
}