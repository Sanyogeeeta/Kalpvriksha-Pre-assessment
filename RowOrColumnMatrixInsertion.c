//User defined insertion- Row measure/column measure
#include <stdio.h>
#include<stdlib.h>

int main()
{
   int size,choice;
   int **matrix;
   printf("Enter size:");
   scanf("%d",&size);
   
   printf("Enter your choice:");
   printf("1-Leeft to right/2-top to bottom");
   scanf("%d",&choice);

   
   matrix=malloc(sizeof(int*)*size);
   for(int i=0;i<size;i++)
        matrix[i]=malloc(sizeof(int)*size);
        
   if(choice==1){
       for(int i=0;i<size;i++){
           for(int j=0;j<size;j++){
               scanf("%d",&matrix[i][j]);
           }
       }
   }
   else if(choice==2){
       for(int i=0;i<size;i++){
           for(int j=0;j<size;j++){
               scanf("%d",&matrix[j][i]);
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
}