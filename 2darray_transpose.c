/*

A single string where rows are delimited by commas. For example: "abcd,efgh,ijkl"
Output:

Transposed 2D array as a list of strings.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[200];
    char matrix[50][50];
    int no_of_rows, no_of_cols,rows=0,cols=0, i = 1;
    scanf("%[^\n]", str);
    int len = strlen(str);
    while (str[i] != '\0')
    {
       if(str[i]=='"')
            break;
       else if (str[i] == ',')
        {
            matrix[rows][cols]='\0';
            rows += 1;
            cols = 0;
        }

        else
        {
            matrix[rows][cols] = str[i];
            cols += 1;
        }
        i++;
    }
    matrix[rows][cols]='\0';
    no_of_cols=cols;
    no_of_rows=rows+1;
    printf("%d %d\n",no_of_cols,no_of_rows);

    for (int col = 0; col < no_of_cols; col++)
    {
        for (int row = 0; row < no_of_rows; row++)
        {
            if(matrix[row][col]!='\0')
                printf("%c ", matrix[row][col]);
        }
        printf("\n");
    }
}