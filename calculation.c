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
    x=numStack[topnum--];
    y=numStack[topnum--];
    op=opStack[topop--];
    switch(op){
        case '+':z=x+y;
            break;
        case '-':z=x-y;
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
    return numStack[topnum];
}
int main(){
    //The user input for expression in string format
    char exp[50];
    printf("Enter Mathematical expression:");
    fgets(exp, sizeof(exp),stdin);
    int i, j = 0;
    /*
    //Alternate approach if dont want to ignore it during evaluation and remove it completely from string
    for (i = 0; i<strlen(exp); i++) {
        if(exp[i]!=' ' && exp[i]!='\0' && exp[i]!='\n'){
            exp[j++] = exp[i];
        }
    }
    exp[j] = '\0';
    */
    int res=0;
    res=evaluation(exp);
    printf("The result is %d",res);
}