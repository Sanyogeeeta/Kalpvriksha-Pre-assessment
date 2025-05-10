#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct node
{
    char c;
    struct node *next;
} node;

int is_empty(node *head)
{
    return head == NULL;
}
node *create(char c)
{
    node *new = malloc(sizeof(node));
    new->next = NULL;
    new->c = c;
    return new;
}

void push(node **head, char c)
{
    node *new = create(c);
    if (*head == NULL)
    {
        *head = new;
    }
    else{
    new->next = (*head);
    *head = new;
    }
}

void pop(node **head)
{
    if (*head == NULL)
    {
        return;
    }
    node *temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void undo(node **head, char str[])
{
    int len = strlen(str) - 1;
    push(head, str[len]);
    str[len] = '\0';
}

void redo(node **head1, node **head2, char str[])
{
    int len = strlen(str);
    char c;
    if(!is_empty(*head1))
    {
        c=(*head1)->c;
        pop(head1);
    }
    push(head2, c);
    str[len] = c;
    str[len + 1] = '\0';
}

int main()
{
    node *head1 = NULL, *head2 = NULL;
    char str[100], choice;

    scanf("%s", str);
    while (choice != 'N')
    {
        printf("Enter Z for Undo and Y for redo and N to exit\n");
        getchar();
        scanf("%c",&choice);
        switch (choice)
        {
            case 'Z' : undo(&head1,str);
            printf("%s\n",str);
            break;
            case 'Y' : redo(&head1,&head2,str);
            printf("%s\n",str);
            break;
            case 'N':
            return 0;
            default:
            printf("invalid!");
        }
    }
    return 0;
}