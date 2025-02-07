#include<stdio.h>
#include<string.h>

int search(char *str, char str1[][101], int n) 
{
    int i;
    for(i = 0; i < n; i++) 
    {
        if(strcmp(str, str1[i]) == 0) 
        {
            return i;
        }
    }
    return -1;
}

int main() 
{
    int n, i;
    char str[202];
    char src[100000][101], dst[100000][101];
    
    scanf("%d", &n);
    getchar();

    for(i = 0; i < n; i++) 
    {
        scanf("%[^\n]%*c", str);
        char *token = strtok(str, "->");
        while(token != NULL && token[strlen(token)-1] == ' ')
        {
            token[strlen(token)-1] = '\0';
        }
        while(token != NULL && *token == ' ')
        {
            token++;
        }
        if(token != NULL)
        {
            strcpy(src[i], token);
        }

        token = strtok(NULL, "->");
        while(token != NULL && token[strlen(token)-1] == ' ')
        {
            token[strlen(token)-1] = '\0';
        }
        while(token != NULL && *token == ' ')
        {
            token++;
        }
        if(token != NULL)
        {
            strcpy(dst[i], token);
        }
    }

    int index = -1;
    for(i = 0; i < n; i++) 
    {
        int flag = 1;
        for(int j = 0; j < n; j++) 
        {
            if(strcmp(src[i], dst[j]) == 0) 
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1) 
        {
            index = i;
            break;
        }
    }

    printf("%s->%s", src[index], dst[index]);
    int current = index;
    for(i = 0; i < n-1; i++) 
    {
        current = search(dst[current], src, n);
        if(current != -1) 
        {
            printf(", %s->%s", src[current], dst[current]);
        }
    }

    return 0;
}
