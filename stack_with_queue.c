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

void push(queue* q,int value) {
    enqueue(q, value);
    int count=q->rear;
    while(q->front<count){
        enqueue(q,q->arr[q->front]);
        dequeue(q);
    }

}

void pop(queue* q) {
    if (is_empty(q)) {
        printf("Stack is empty\n");
        return;
    }
    dequeue(q);
}

int size(queue* q) {
    if (is_empty(q)) {
        return 0;
    }
    return q->rear - q->front + 1;
}

int main() {
    queue q;
    q.front = q.rear = -1;
    int value, choice;

    q.arr = (int*)malloc(sizeof(int) * MAX);
    
    while (choice!=6) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &value);
                push(&q, value);
                break;
            case 2:
                pop(&q);
                break;
            case 3:
                value = peek(&q);
                if (value != -1) {
                    printf("%d\n", value);
                } else {
                    printf("Stack is empty\n");
                }
                break;
            case 4:
                if (is_empty(&q)) {
                    printf("True\n");
                } else {
                    printf("False\n");
                }
                break;
            case 5:
                printf("%d\n", size(&q));
                break;
            case 6:
                free(q.arr);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}