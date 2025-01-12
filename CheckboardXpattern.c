//X pattern matrix:

#include <stdio.h>
#include<stdlib.h>

int main()
{
    int size;
    int** matrix;
    int input_x;
    
    printf("Enter size:");
   scanf("%d",&size);
   
   matrix=malloc(sizeof(int*)*size);
   for(int i=0;i<size;i++)
        matrix[i]=malloc(sizeof(int)*size);
    
    
    

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            matrix[i][j]=0;
        }
    }
    
    
    printf("Enter input for x pattern:\n");
    scanf("%d",&input_x);
    
    for(int i=0;i<size;i++){
        matrix[i][i]=input_x;
    }
    
    for(int i=0;i<size;i++){
        int j=size-1-i;
        matrix[i][j]=input_x;
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