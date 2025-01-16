#include <stdio.h>
#include <string.h> // For strcpy

int main() {
   int rows,cols;
    char array[100][100]; // Array to hold input with null terminators
    scanf("%d",&rows);
    char temp[100];

    for (int i = 0; i < rows; i++) {
        scanf("%s",temp);
        int cols=strlen(temp);
        printf("%d",temp[cols]);
        for (int j = 0; j <= cols; j++) {
            array[i][j]=temp[j]; // Read characters
        }
        //array[i][cols] = '\0'; // Add null terminator at the end of each row
    }

    for (int i = 0; i < rows; i++) {
        printf("%s\n", array[i]); // Print string starting from `k`
    }

    return 0;
}