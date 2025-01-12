//Take user input for diagonal elemts and boundary elements place remaining elements as 0
#include <stdio.h>
#include<stdlib.h>

int main()
{
    int size,count=0;
    int** matrix;
    int boundary_ele;
    printf("Enter size of matrix:");
    scanf("%d",&size);
    
    matrix=malloc(sizeof(int*)*size);
    for(int i=0;i<size;i++)
        matrix[i]=malloc(sizeof(int)*size);
        
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            matrix[i][j]=0;
        }
    }
        
    printf("Enter %d diagonal elements:",size);
    for(int i=0;i<size;i++)
        scanf("%d",&matrix[i][i]);
        
    printf("Enter %d anti-diagonal elements:",size);
    for(int i=0;i<size;i++){
        int j=size-1-i;
        if (i != j)
        scanf("%d",&matrix[i][j]);
    }
        
    printf("Enter boundary elements:");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i==0||i==size-1||j==0||j==size-1){
                if(matrix[i][j]==0){
                     if (i != j && i != size - 1 - j) {
                        scanf("%d",&matrix[i][j]);
                     }
                }
            }
        }
    }
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
        
    return 0;
}