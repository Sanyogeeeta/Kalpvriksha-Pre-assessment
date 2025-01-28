#include <stdio.h>
#include <stdlib.h>

/*
You are given a singly linked list of integers and a positive integer k.
Your task is to reverse the list in groups of size k. Once the current group has been reversed,
move to the next group of size k and repeat the process until the end of the list.
 
If the number of remaining nodes in the list is less than k, reverse all the remaining nodes as one group.
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

void reverse(node **head, node *end)
{
    node *current = *head, *next = NULL, *prev = NULL;
    while (current != end)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    if (*head != NULL)
        (*head)->next = end;
    *head = prev;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Bubble_sort(node *start, node *end)
{

    if (start == NULL || start->next == NULL)
        return;
    node *outer = start;
    node *lstptr = end;
    while (outer != lstptr)
    {
        node *inner = start;
        int swapped = 0;
        while (inner->next != lstptr)
        {
            if (inner->value > inner->next->value)
            {
                swap(&inner->value, &inner->next->value);
                swapped = 1;
            }
            inner = inner->next;
        }
        if (!swapped)
            break;
        lstptr = inner;
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
    int k;
    scanf("%d", &k);

    node *first = head, *last = head, *prev = NULL;
    while (first != NULL)
    {

        int i = 0;
        while (last != NULL && i != k)
        {
            last = last->next;
            i++;
        }
        reverse(&first, last);
        Bubble_sort(first, last);

        if (prev != NULL)
            prev->next = first;
        else
            head = first;

        while (first->next != NULL && first->next != last)
        {
            first = first->next;
        }

        prev = first;
        first = last;
    }

    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }

    return 0;
}