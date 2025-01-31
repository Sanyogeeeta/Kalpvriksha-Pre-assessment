#include <stdio.h>
#include <stdlib.h>
#define MAX 100

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

void pop(stack *s) {
    if (is_empty(s)) {
        return;
    }
    s->top -= 1;
}

void push(stack* s, int value) {
    if (is_full(s)) {
        return;
    }
    s->top += 1;
    s->arr[s->top] = value;
}

void enqueue(stack* s, int value) {
    push(s, value);
}

void dequeue(stack* s1, stack* s2) {
    if (is_empty(s2)) {
        while (s1->top >= 0) {
            push(s2, s1->arr[s1->top]);
            pop(s1);
        }
    }
    if (!is_empty(s2)) {
        pop(s2);
    }
}

int peek(stack* s1, stack* s2) {
    if (is_empty(s2)) {
        while (s1->top >= 0) {
            push(s2, s1->arr[s1->top]);
            pop(s1);
        }
    }
    if (!is_empty(s2)) {
        return s2->arr[s2->top];
    }
    return -1;
}

int size(stack* s1, stack* s2) {
    return s1->top + s2->top + 2;
}

int main() {
    stack s1, s2;
    s1.top = -1;
    s2.top = -1;
    int value, choice = 0;

    s1.arr = (int*)malloc(sizeof(int) * MAX);
    s2.arr = (int*)malloc(sizeof(int) * MAX);

    while (choice != 6) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &value);
                enqueue(&s1, value);
                break;
            case 2:
                dequeue(&s1, &s2);
                break;
            case 3:
                value = peek(&s1, &s2);
                if (value != -1) {
                    printf("%d\n", value);
                } else {
                    printf("Queue is empty\n");
                }
                break;
            case 4:
                if (is_empty(&s1) && is_empty(&s2)) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                printf("%d\n", size(&s1, &s2));
                break;
            case 6:
                free(s1.arr);
                free(s2.arr);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
