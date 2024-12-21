#include<stdio.h>
#include<string.h>

//store number and operator in stack
int number[30];
int topnum=-1;
char operator[20];
int topop=-1;

//Check for Digit
int IsDigit(char c){
    int flag=0;
    if(c>='0' && c<='9')
        flag=1;
    return flag;
}

//Perform arithmetic operation
void PerformOperation(){
    int num1,num2,result;
    char op;
    if(topnum>=1 && topop>=0){
        num1=number[topnum--];
        num2=number[topnum--];
        op=operator[topop--];
        switch(op){
            case '+':result=num2+num1;
                break;
            case '-':result=num2-num1;
                break;
            case '*':result=num2*num1;
                break;
            case '/':
                if(num1==0){
                    printf("Error: Division by zero.\n");
                    return;
                }
                result=num2/num1;
                break;
        }
        number[++topnum]=result;
    }
    else{
        topnum=-1;
        topop=-1;
        printf("Error: Invalid expression(Missing operand.)\n");
        return;
    }
}

//operator precedence
int precedence(char c){
    int result;
    if(c=='+'||c=='-')
        result=1;
    else if(c=='*'||c=='/')
        result=2;
    return result;
}

//Expression evaluation
int Evaluation(char exp[]){
    int i;
    char c;
    for(i=0;i<strlen(exp)-1;i++){
        c=exp[i];
        if(c==' ')
            continue;
        //check for digit and add to number stack
        else if(IsDigit(c)){         
            int num=0;
            while(IsDigit(c)){
                num=num*10+(c-'0');
                i++;
                if(i<strlen(exp))
                    c=exp[i];
                else
                    break;
            }
            number[++topnum]=num;
            i--;
        }
        else if(c=='+'||c=='-'||c=='*'||c=='/'){
            while(!(topop==-1) && (precedence(c)<=precedence(operator[topop]))){
                PerformOperation();
            }
            operator[++topop]=c;
        }
        else{
            return -999;
        }
    }
    while(topop!=-1)
        PerformOperation();
    if((topop==-1 && topnum!=0)||topnum==-1)
        return -999;
    return number[topnum];
}

int main(){
    //The user input for expression in string format
    char exp[50];
    printf("Enter Mathematical expression:");
    fgets(exp, sizeof(exp),stdin);
    int i, j = 0;
    int res=0;
    res=Evaluation(exp);
    if(strlen(exp)==0||(strlen(exp)==1 && !(strcmp(" ",exp)))||res==-999){
        printf("Error: Invalid expression\n");
    }
    else
        printf("The result is %d\n",res);
    return 0;
}