//Boundary sum:

#include <stdio.h>
#include<stdlib.h>

int main()
{
    int size;
    int** matrix;
    int left_cord,top_cord,bottom_cord,right_cord;
    int row=0,col=0,boundary_sum=0;
    
    printf("Enter size:");
   scanf("%d",&size);
   
   matrix=malloc(sizeof(int*)*size);
   for(int i=0;i<size;i++)
        matrix[i]=malloc(sizeof(int)*size);
    
    while(scanf("%d",&matrix[row][col])==1){
        col++;
        if(col==size){
            col=0;
            row+=1;
        }
        if(row==size) break;
    }
    
    

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i==0||j==0||i==size-1||j==size-1)
            boundary_sum+=matrix[i][j];
        }
    }
    
    printf("%d",boundary_sum);
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}