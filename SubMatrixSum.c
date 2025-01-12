//Sum of all elements in sub-matrix given by user
#include <stdio.h>
#include<stdlib.h>

int main()
{
    int size;
    int** matrix;
    int left_cord,top_cord,bottom_cord,right_cord;
    char str[200];
    int row=0,col=0,sum=0;
    
     printf("Enter size:");
   scanf("%d",&size);
   
   matrix=malloc(sizeof(int*)*size);
   for(int i=0;i<size;i++)
        matrix[i]=malloc(sizeof(int)*size);
    
    scanf("%[\n]",str);
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
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("Enter left right,top-bottom coordinates of sub matrix:");
    scanf("%d %d %d %d",&left_cord,&right_cord,&top_cord,&bottom_cord);
    
    if(left_cord<0||right_cord>size||top_cord<0||bottom_cord>size || left_cord > right_cord || top_cord > bottom_cord)
        printf("Invalid coordinates\n");

    for(int i=top_cord;i<=bottom_cord;i++){
        for(int j=left_cord;j<=right_cord;j++){
            sum+=matrix[i][j];
        }
    }
    
    printf("%d",sum);
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}