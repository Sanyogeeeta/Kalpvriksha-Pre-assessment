#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
Given two singly linked lists, the task is to:
 
Merge the two lists into one sorted list using Merge Sort.
Split the merged list into two lists such that:
The first list contains all nodes with values less than the median.
The second list contains all nodes with values greater than or equal to the median.
*/
typedef struct node
{
    int value;
    struct node *next;
} node;

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

node *middleElement(node *head)
{
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node *merge(node *first, node *second)
{
    node *temp1 = first, *head = NULL;
    node *temp2 = second;
    node *current = NULL;
    while (temp1 != NULL && temp2 != NULL)
    {
        node *new_node;
        if (temp1->value < temp2->value)
        {
            new_node = temp1;
            temp1 = temp1->next;
        }
        else
        {
            new_node = temp2;
            temp2 = temp2->next;
        }
        if (head == NULL)
        {
            head = new_node;
            current = new_node;
        }
        else
        {
            current->next = new_node;
            current = current->next;
        }
    }
    if (temp1 != NULL)
    {
        current->next = temp1;
    }
    else
    {
        current->next = temp2;
    }
    return head;
}

node *merge_sort(node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    node *middle = middleElement(head);
    node *second = middle->next;
    middle->next = NULL;

    head = merge_sort(head);
    second = merge_sort(second);
    return merge(head, second);
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

int main()
{
    int value;
    node *head1 = NULL, *head2 = NULL, *head = NULL;

    while (scanf("%d", &value) == 1)
    {
        insertion(&head1, value);
        if (getchar() == '\n')
            break;
    }

    while (scanf("%d", &value) == 1)
    {
        insertion(&head2, value);
        if (getchar() == '\n')
            break;
    }

    display(head1);
    display(head2);

    head = merge(head1, head2);
    display(head);

    node *middle = middleElement(head1);

    node *temp = head;
    while (temp->next != middle)
        temp = temp->next;

    temp->next = NULL;

    head1 = head;
    head2 = middle;
    display(head1);
    display(head2);
    return 0;
}