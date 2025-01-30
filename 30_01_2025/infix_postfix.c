#include<stdio.h>
#include<string.h>

int isOperator(char c){
    return (c == '+' || c == '*' || c == '-' || c == '/' || c == '^');
}

int isOperand(char c){
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int precedence(char c){
    int order = 0;
    if(c == '+' || c == '-') order = 1;
    else if(c == '*' || c == '/') order = 2;
    else if(c == '^') order = 3;
    return order;
}

char pop(char* stack, int* top){
    if(*top == -1)
        return '!';  
    return stack[(*top)--];
}

void push(char* stack, int* top, char c){
    (*top)++;
    stack[(*top)] = c;
}

void Postfix(char* res, char* stack, char *ptr, int* top){
    char temp[2];  
    int res_idx = 0;  
    res[0] = '\0';  

    while(*ptr != '\0'){
        if(*ptr == '('){
            push(stack, top, *ptr);
        }
        else if(isOperator(*ptr)){
            while(*top != -1 && precedence(stack[*top]) >= precedence(*ptr)){
                temp[0] = pop(stack, top);  
                temp[1] = '\0';  
                strcat(res, temp);  
            }
            push(stack, top, *ptr);
        }
        else if(*ptr == ')'){
            while(*top != -1 && stack[*top] != '('){
                temp[0] = pop(stack, top);  
                temp[1] = '\0';  
                strcat(res, temp);  
            }
            pop(stack, top);  
        }
        else if(isOperand(*ptr)){
            temp[0] = *ptr;  
            temp[1] = '\0';  
            strcat(res, temp);  
        }
        ptr++;
    }

    while(*top != -1){
        temp[0] = pop(stack, top);  
        temp[1] = '\0';  
        strcat(res, temp);  
    }
}

int main(){
    char stack[100];
    int top = -1;
    char str[100];
    char result[100];

    scanf("%s", str);

    Postfix(result, stack, str, &top);

    printf("%s\n", result);
    return 0;
}
