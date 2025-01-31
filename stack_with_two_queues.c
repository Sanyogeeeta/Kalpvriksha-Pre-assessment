#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct queue {
    int* arr;
    int front, rear;
} queue;

int is_full(queue* q) {
    return q->rear == MAX - 1;
}

int is_empty(queue* q) {
    return q->front == -1;
}

void enqueue(queue* q, int value) {
    if (is_full(q)) {
        printf("Queue is full\n");
        return;
    }
    if (is_empty(q)) {
        q->front = 0;
    }
    q->arr[++q->rear] = value;
}

void dequeue(queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
}

int peek(queue* q) {
    if (is_empty(q)) {
        return -1;
    }
    return q->arr[q->front];
}

void push(queue* q1, queue* q2, int value) {
    enqueue(q2, value);
    while (!is_empty(q1)) {
        enqueue(q2, peek(q1));
        dequeue(q1);
    }
    queue temp = *q1;
    *q1 = *q2;
    *q2 = temp;
}

void pop(queue* q1) {
    if (is_empty(q1)) {
        printf("Stack is empty\n");
        return;
    }
    dequeue(q1);
}

int size(queue* q1) {
    if (is_empty(q1)) {
        return 0;
    }
    return q1->rear - q1->front + 1;
}

int main() {
    queue q1, q2;
    q1.front = q1.rear = -1;
    q2.front = q2.rear = -1;
    int value, choice;

    q1.arr = (int*)malloc(sizeof(int) * MAX);
    q2.arr = (int*)malloc(sizeof(int) * MAX);

    while (choice!=6) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &value);
                push(&q1, &q2, value);
                break;
            case 2:
                pop(&q1);
                break;
            case 3:
                value = peek(&q1);
                if (value != -1) {
                    printf("%d\n", value);
                } else {
                    printf("Stack is empty\n");
                }
                break;
            case 4:
                if (is_empty(&q1)) {
                    printf("True\n");
                } else {
                    printf("False\n");
                }
                break;
            case 5:
                printf("%d\n", size(&q1));
                break;
            case 6:
                free(q1.arr);
                free(q2.arr);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}