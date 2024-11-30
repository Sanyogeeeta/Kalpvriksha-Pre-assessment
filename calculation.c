#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
//store number in stack
int numStack[30];
int topnum=-1;
//store operators in stack
char opStack[20];
int topop=-1;
//Perform arithmetic operation
void calculate(){
    int x,y,z,n;
    char op;
    //To check there are minimum two operands
    if(topnum>=1){
    x=numStack[topnum--];
    y=numStack[topnum--];
    op=opStack[topop--];
    switch(op){
        case '+':z=x+y;
            break;
        case '-':z=y-x;
            break;
        case '*':z=x*y;
            break;
        case '/':
        //Division by zero check
            if(x==0){
                printf("Error: Division by zero.");
                exit(0);
            }
            z=y/x;
            break;
    }
    numStack[++topnum]=z;
    }
    else{
        topnum=-1;
        topop=-1;
        printf("Error: Invalid expression(Missing operand.)");
    }
}
//operator precedence
int precedence(char c){
if(c=='+'||c=='-')
    return 1;
else if(c=='*'||c=='/')
    return 2;
}
int evaluation(char exp[]){
    int i;
    char c;
    for(i=0;i<strlen(exp)-1;i++){
    c=exp[i];
    //ignore the white space
    if(c==' ')
        continue;
    //check for digit and add to number stack
    else if(isdigit(c)){
            //multinum calculation           
            int x=0;
            while(isdigit(c)){
                x=x*10+(c-'0');
                i++;
                if(i<strlen(exp))
                    c=exp[i];
                else
                    break;
            }
            //printf("%d\n",x);
            numStack[++topnum]=x;
            i--;
        }
        //check for operators and add to operator stack
        else if(c=='+'||c=='-'||c=='*'||c=='/'){
            while(!(topop==-1) && (precedence(c)<=precedence(opStack[topop]))){
                calculate();
            }
            opStack[++topop]=c;
            //printf("%c\n",opStack[topop]);
        }
        //Invalid inputs
        else{
            printf("'Error: Invalid expression.");
            exit(0);
        }
    }
    while(topop!=-1)
        calculate();
    //if there is experssio error return -999
    if(topnum==-1){
        return -999;
    }
    return numStack[topnum];
}
int main(){
    //The user input for expression in string format
    char exp[50];
    printf("Enter Mathematical expression:");
    fgets(exp, sizeof(exp),stdin);
    if(strlen(exp)==0||(strlen(exp)==1 && !(strcmp(" ",exp)))){
    //Handle empty or just space expression
        printf("Error: Invalid expression\n");
        return 0;
    }
    else{
    int i, j = 0;
    int res=0;
    res=evaluation(exp);
    if(res==-999){
        return 0;
    }
    else
    printf("The result is %d",res);
    }
}