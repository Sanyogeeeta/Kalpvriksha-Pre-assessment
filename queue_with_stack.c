#include <stdio.h>
#include <stdlib.h>
 
typedef struct stack {
    int* arr;
    int top;
} stack;
 
int is_full(stack* s) {
    return s->top == MAX - 1;
}
 
int is_empty(stack* s) {
    return s->top == -1;
}
 
void push(stack* s, int value) {
    if (is_full(s)) {
        return;
    }
    s->arr[++(s->top)] = value;
}
 
int pop(stack* s) {
    if (is_empty(s)) {
        return -1;
    }
    return s->arr[(s->top)--];
}
 
int dequeue(stack* s) {
    if (is_empty(s)) {
        printf("Queue is empty\n");
        return -1;
    }
    
    int top_element = pop(s);
 
    if (is_empty(s)) {  
        return top_element;
    }
 
    int result = dequeue(s);
 
    push(s, top_element);
 
    return result;
}
 
int peek(stack* s) {
    if (is_empty(s)) {
        printf("Queue is empty\n");
        return -1;
    }
 
    int top_element = pop(s);
 
    if (is_empty(s)) {
        push(s, top_element);
        return top_element;
    }
 
    int front = peek(s);
 
    push(s, top_element);
 
    return front;
}
 
int size(stack* s) {
    return s->top + 1;
}
 
int main() {
    stack s;
s.top = -1;
    s.arr = (int*)malloc(sizeof(int) * MAX);
 
    int value, choice = 0;
 
    while (choice != 6) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = dequeue(&s);
                if (value != -1) {
                    printf("%d dequeued\n", value);
                }
                break;
            case 3:
                value = peek(&s);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 4:
                printf(is_empty(&s) ? "Queue is empty\n" : "Queue is not empty\n");
                break;
            case 5:
                printf("Size: %d\n", size(&s));
                break;
            case 6:
                free(s.arr);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
