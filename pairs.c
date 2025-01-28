#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

/*
Given a singly linked list, you are tasked with finding all unique pairs of nodes whose values sum up to a given target. Each pair must be printed in the form of the two node values.
You are required to implement the function findPairs, which takes the head of the linked list and the target sum as inputs and prints the pairs that add up to the target.
*/
node *create_node(int value)
{
    node *new_node = malloc(sizeof(node));
    new_node->next = NULL;
    new_node->value = value;
    return new_node;
}

void insertion(node **head, int value)
{
    node *new_node = create_node(value);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void display(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void findPairs(node *head, int target)
{
    if (head == NULL)
        return;

    node *left = head;
    node *right;

    while (left != NULL)
    {
        right = left->next;
        while (right != NULL)
        {
            if (left->value + right->value == target)
            {
                printf("%d %d\n", left->value, right->value);
            }
            right = right->next;
        }
        left = left->next;
    }
}

int main()
{
    int value;
    node *head = NULL;

    while (scanf("%d", &value) == 1)
    {
        insertion(&head, value);
        if (getchar() == '\n')
            break;
    }

    int target;
    scanf("%d", &target);

    findPairs(head, target);

    return 0;
}