#include<stdio.h>
#include<string.h>

int IsDigit(char c){
    int flag=0;
    if(c>='0' && c<='9')
        flag=1;
    return flag;
}

void PerformOperation(int* number,char* operator,int* topno,int* topoper){
    int num1,num2,result;
    int topnum=*topno;
    int topop=*topoper;
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
                    *topno=-1;
                    *topoper=-1;
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
    }
    *topno=topnum;
    *topoper=topop;
}

int precedence(char c){
    int result;
    if(c=='+'||c=='-')
        result=1;
    else if(c=='*'||c=='/')
        result=2;
    return result;
}

int Evaluation(char exp[]){    
    int number[30];
    char operator[20];
    int topop=-1;
    int topnum=-1;
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
                PerformOperation(number,operator,&topnum,&topop);
            }
            operator[++topop]=c;
        }
        else{
            topnum=0;
            number[topnum]=-999;
        }
    }
    while(topop!=-1)
        PerformOperation(number,operator,&topnum,&topop);
    if((topop==-1 && topnum!=0)||topnum==-1)
        number[++topnum]=-999;
    return number[topnum];
}

int main(){
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