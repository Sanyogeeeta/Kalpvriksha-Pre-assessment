#include<stdio.h>
#include<stdlib.h>


/*
You are given a rotated sorted singly linked list. The list is initially sorted in ascending order,
but it has been rotated at some pivot point.
Your task is to find the minimum element in the rotated sorted list.

Input:
A singly linked list where each node contains an integer value.
The linked list is initially sorted in ascending order but has been rotated at some unknown pivot.
*/
typedef struct node{
    int value;
    struct node* next;
}node;

node* create_node(int value){
    node* new_node = malloc(sizeof(node));
    new_node->next = NULL;
    new_node->value = value;
    return new_node;
}

void insertion(node** head, int value){
    node* new_node = create_node(value);
    if (*head == NULL){
        *head = new_node;
        return;
    }
    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

int list_length(node* head) {
    int length = 0;
    node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

node* find_min(node* head) {
    if (head == NULL) return NULL;

    node* left = head;
    node* right = head;

    while (right->next != NULL) {
        right = right->next;
    }

    while (left != right) {
        node* mid = left;
        while (mid->next != right && mid->next != NULL) {
            mid = mid->next;
        }

        if (mid->value <= right->value) {
            right = mid;
        } else {
            left = mid->next;
        }
    }

    return left;
}

int main() {
    int value;
    node* head = NULL;
    
    while (scanf("%d", &value) == 1) {
        insertion(&head, value);
        if (getchar() == '\n') break;
    }   
    display(head);

    node* min = find_min(head);
    printf("%d\n", min->value);

    return 0;
}
