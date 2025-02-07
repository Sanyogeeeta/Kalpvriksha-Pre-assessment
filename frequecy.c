#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct HashMap
{
    char log[100];
    int count;
} map;
 
map *takeInput()
{
    char input[10000];
    int limit, size = 0;
    map *freq = NULL;
 
    scanf(" %[^\n]s", input);
    scanf("%d", &limit);
 
    char *token = strtok(input, " ");
 
    while (token)
    {
        int found = 0;
 
        for (int index = 0; index < size; index++)
        {
            if (strcmp(freq[index].log, token) == 0)
            {
                freq[index].count++;
                found = 1;
                break;
            }
        }
 
        if (!found)
        {
            freq = realloc(freq, (size + 1) * sizeof(map));
            strcpy(freq[size].log, token);
            freq[size].count = 1;
            size++;
        }
 
        token = strtok(NULL, " ");
    }
 
    printf("[");
    int first = 1;
    for (int index = 0; index < size; index++)
    {
        if (freq[index].count < limit)
        {
            if (!first)
            {
                printf(", ");
            }
            printf("\"%s\"", freq[index].log);
            first = 0;
        }
    }
    printf("]");
 
    return freq;
}
 
int main()
{
    takeInput();
    return 0;
}