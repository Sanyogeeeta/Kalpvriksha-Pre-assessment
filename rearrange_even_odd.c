#include <stdio.h>
#include <stdlib.h>

/*
You are given a singly linked list where each node contains an integer.
The task is to rearrange the list such that all the odd elements come first,
followed by all the even elements
*/
typedef struct node {
    int value;
    struct node* next;
} node;

node* create(int value) {
    node* new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void insertion(node** head, int value) {
    node* temp = *head;
    if (temp == NULL) {
        *head = create(value);
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = create(value);
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

node* partition(node* head, node** left, node** right) {
    if (head == NULL || head->next == NULL) return head;

    node* pivot = head;
    node* temp = head->next;
    node* left_head = NULL, *left_tail = NULL;
    node* right_head = NULL, *right_tail = NULL;

    while (temp != NULL) {
        if (temp->value % 2 != 0) {
            if (left_head == NULL) {
                left_head = temp;
                left_tail = temp;
            } else {
                left_tail->next = temp;
                left_tail = temp;
            }
        } else {
            if (right_head == NULL) {
                right_head = temp;
                right_tail = temp;
            } else {
                right_tail->next = temp;
                right_tail = temp;
            }
        }
        temp = temp->next;
    }

    if (left_tail) left_tail->next = NULL;
    if (right_tail) right_tail->next = NULL;

    *left = left_head;
    *right = right_head;

    return pivot;
}

node* quick_sort(node* head) {
    if (head == NULL || head->next == NULL) return head;

    node* left = NULL, *right = NULL;
    node* pivot = partition(head, &left, &right);

    left = quick_sort(left);
    right = quick_sort(right);

    if (left == NULL) {
        pivot->next = right;
        return pivot;
    }

    node* temp = left;
    while (temp->next != NULL) temp = temp->next;

    temp->next = pivot;
    pivot->next = right;

    return left;
}

int main() {
    node* head = NULL;
    int value;

    while(scanf("%d", &value) == 1) {
        insertion(&head, value);
        if (getchar() == '\n') break;
    }

    head = quick_sort(head);
    display(head);

    return 0;
}
