#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    int **matrix;
    int row=0,col=0;
    char c;
    scanf("%d",&n);
    getchar();
    matrix=(int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * n);
    }
    while(scanf("%d",&matrix[row][col])){
        col++;
        if(col==n){
            col=0;
            row+=1;
            if(row==n)break;
        }
    }

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            printf("%d ",matrix[row][col]);
        }
        printf("\n");
    }    
    
    for(int i=0;i<n;i++){
        int j=i;
        int temp=matrix[i][j];
        matrix[i][j]=matrix[i][n-1-j];
        matrix[i][n-1-j]=temp;
    }

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            printf("%d ",matrix[row][col]);
        }
        printf("\n");
    } 

    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}