#include<stdio.h>
#include<stdlib.h>

void push(char* stack, int* top, char value) {
    (*top)++;
    stack[*top] = value;
}

void pop(int* top) {
    if (*top == -1) {
        return;
    }
    (*top)--;
}

int main() {
    char stack[100];
    int top = -1;
    char ch;
    
    while (1) {
        scanf("%c", &ch);
        if (ch == '\n') {
            break;
        }
        push(stack, &top, ch);
    }
    
    while (top != -1) {
        printf("%c", stack[top]);
        pop(&top);
    }
    printf("\n");

    return 0;
}
