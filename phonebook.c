#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 100
 
typedef struct phonebook
{
    char key[30];
    int value;
    struct phonebook *next;
} phonebook;
 
typedef struct HashTable
{
    phonebook *p[SIZE];
} HashTable;
 
int hash_function(char *str)
{
    unsigned long hash = 5381;
    int character;
    while ((character = *str++))
        hash = ((hash << 5) + hash) + character;
    return hash % SIZE;
}
 
void addphonebook(HashTable *table, char *key, int value)
{
    int index = hash_function(key);
    phonebook *current = table->p[index];
 
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            current->value = value;
            printf("Success\n");
            return;
        }
        current = current->next;
    }
 
    phonebook *newphonebook = (phonebook *)malloc(sizeof(phonebook));
    strcpy(newphonebook->key, key);
    newphonebook->value = value;
    newphonebook->next = table->p[index];
    table->p[index] = newphonebook;
 
    printf("Success\n");
}
 
void findphonebook(HashTable *table, char *key)
{
    int index = hash_function(key);
    phonebook *current = table->p[index];
 
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            printf("%d\n", current->value);
            return;
        }
        current = current->next;
    }
    printf("Not Found\n");
}
 
void removephonebook(HashTable *table, char *key)
{
    int index = hash_function(key);
    phonebook *current = table->p[index];
    phonebook *prev = NULL;
 
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            if (prev == NULL)
            {
                table->p[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            printf("Success\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Not Found\n");
}
 
int main()
{
    int count;
    scanf("%d\n", &count);
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
 
    for (int index = 0; index < count; index++)
    {
        table->p[index] = NULL;
    }
 
    for (int index = 0; index < count; index++)
    {
        char input[100];
        fgets(input, sizeof(input), stdin);
 
        char key[20];
        int value;
        if (sscanf(input, " add(\"%19[^\"]\", %d) ", key, &value) == 2)
        {
            addphonebook(table, key, value);
        }
 
        else if (sscanf(input, " search(\"%19[^\"]\") ", key) == 1)
        {
            findphonebook(table, key);
        }
 
        else if (sscanf(input, " delete(\"%19[^\"]\") ", key) == 1)
        {
            removephonebook(table, key);
        }
    }
    return 0;
}