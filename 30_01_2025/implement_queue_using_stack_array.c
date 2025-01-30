#include<stdio.h>
#include<stdbool.h>

void push(int* stack, int *top, int value, int capacity){
    if(*top == capacity - 1){
        printf("FULL\n");
        return;
    }
    (*top)++;
    stack[*top] = value;
}

void pop(int* stack1, int* stack2, int* top1, int* top2, int size){
    if(*top1 < 0 && *top2 < 0){
        printf("Empty\n");
        return;
    }
    *top2 = -1;
    while(*top1 >= 0){
        push(stack2, top2, stack1[*top1], size);
        (*top1)--;
    }
    (*top2)--;
    int temp = stack2[*top2];
    
    while(*top2 >= 0){
        push(stack1, top1, stack2[*top2], size);
        (*top2)--;
    }
    stack2[*top2] = temp;
}

bool isEmpty(int top){
    return top < 0;
}

int back(int stack[], int top){
    if(top == -1)
        return 0;
    return stack[top];
}

int size_queue(int top){
    return top + 1;
}

int front(int stack[], int top){
    if(top == -1)
        return 0;
    return stack[top];
}

void queue_details(int stack1[], int stack2[], int top1, int top2){
    printf("%d %d %d %d\n", front(stack2, top2), back(stack1, top1), isEmpty(top1 + top2), size_queue(top1));
}

int main(){
    int top1 = -1, top2 = -1;
    int size;
    scanf("%d", &size);
    int stack2[100];
    int stack1[100];
    queue_details(stack1, stack2, top1, top2);

    int choice = 0, value;
    while(choice != 3){
        scanf("%d", &choice);
        switch(choice){
            case 1:
                scanf("%d", &value);
                if(top2 == -1 && top1 == -1){
                    push(stack2, &top2, value, size);
                }
                push(stack1, &top1, value, size);
                queue_details(stack1, stack2, top1, top2);
                break;
            case 2:
                pop(stack1, stack2, &top1, &top2, size);
                queue_details(stack1, stack2, top1, top2);
                break;
            case 3:
                return 0;
        }
    }

    return 0;
}
