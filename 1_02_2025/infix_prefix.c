#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isOperator(char c) {
    return (c == '+' || c == '*' || c == '-' || c == '/' || c == '^');
}

int isOperand(char c) {
    return isalnum(c);
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

void reverse(char* expr) {
    int n = strlen(expr);
    for (int i = 0; i < n / 2; i++) {
        char temp = expr[i];
        expr[i] = expr[n - i - 1];
        expr[n - i - 1] = temp;
    }
}

void infixToPrefix(char* result, char* stack, char* expr, int* top) {
    char temp[2];
    result[0] = '\0';

    while (*expr != '\0') {
        if (*expr == ')') {
            push(stack, top, *expr);
        }
        else if (*expr == '(') {
            while (*top != -1 && stack[*top] != ')') {
                temp[0] = pop(stack, top);
                temp[1] = '\0';
                strcat(result, temp);
            }
            pop(stack, top);
        }
        else if (isOperator(*expr)) {
            while (*top != -1 && precedence(stack[*top]) > precedence(*expr)) {
                temp[0] = pop(stack, top);
                temp[1] = '\0';
                strcat(result, temp);
            }
            push(stack, top, *expr);
        }
        else if (isOperand(*expr)) {
            temp[0] = *expr;
            temp[1] = '\0';
            strcat(result, temp);
        }
        expr++;
    }

    while (*top != -1) {
        temp[0] = pop(stack, top);
        temp[1] = '\0';
        strcat(result, temp);
    }
}

void push(char* stack, int* top, char c) {
    (*top)++;
    stack[*top] = c;
}

char pop(char* stack, int* top) {
    if (*top == -1)
        return '!';
    return stack[(*top)--];
}

int main() {
    char stack[100];
    int top = -1;
    char str[100];
    char result[100];

    scanf("%s", str);

    reverse(str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            str[i] = ')';
        } else if (str[i] == ')') {
            str[i] = '(';
        }
    }

    infixToPrefix(result, stack, str, &top);

    reverse(result);

    printf("%s\n", result);

    return 0;
}
