
#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
#define MAX 100
 
int is_empty(int top) {
    return top == -1;
}
 
int pop_int(int stack[], int *top) {
    if (is_empty(*top)) return -1;
    return stack[(*top)--];
}
 
char pop_char(char stack[], int *top) {
    if (is_empty(*top)) return '\0';
    return stack[(*top)--];
}
 
void push_char(char stack[], int *top, char c) {
    if (*top == MAX - 1) return;
    stack[++(*top)] = c;
}
 
void push_int(int stack[], int *top, int c) {
    if (*top == MAX - 1) return;
    stack[++(*top)] = c;
}
 
int main() {
    char str[MAX];
    char stack[MAX];
    int numStack[MAX];
    int top_str = -1, top_num = -1;
    char temp[MAX];
    int num = 0;
 
    scanf("%s", str);
    int len = strlen(str);
 
    for (int i = 0; i < len; i++) {
        if (isdigit(str[i])) {
            num = num * 10 + (str[i] - '0');
        } else if (str[i] == '[') {
            push_int(numStack, &top_num, num);
            push_char(stack, &top_str, '[');
            num = 0;
        } else if (str[i] == ']') {
            int times = pop_int(numStack, &top_num);
            char res[MAX] = "";
            char ch;
            while ((ch = pop_char(stack, &top_str)) != '[') {
                char tempChar[2] = {ch, '\0'};
                strcat(res, tempChar);
            }
        
            int res_len = strlen(res);
            for (int j = 0; j < res_len / 2; j++) {
                char temp_char = res[j];
                res[j] = res[res_len - j - 1];
                res[res_len - j - 1] = temp_char;
            }
    
            for (int j = 0; j < times; j++) {
                for (int k = 0; k < res_len; k++) {
                    push_char(stack, &top_str, res[k]);
                }
            }
        } else {
            push_char(stack, &top_str, str[i]);
        }
    }
 
    int i = 0;
    while (!is_empty(top_str)) {
        str[i++] = pop_char(stack, &top_str);
    }
    str[i] = '\0';
 
    printf("%s\n", str);
    return 0;
}