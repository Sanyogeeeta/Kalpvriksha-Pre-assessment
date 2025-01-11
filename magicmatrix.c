#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,row=0,col=0,rows_same=1,cols_same=1,diagonals_same=1;
    int** matrix;
    int*row_sum,*col_sum;
    int diagonal_sum[2]={0};

    scanf("%d",&n);
    row_sum=malloc(sizeof(int)*n);
    col_sum=malloc(sizeof(int)*n);
    matrix=malloc(sizeof(int*)*n);

    for(int row=0;row<n;row++){
        matrix[row]=malloc(sizeof(int)*n);
        row_sum[row]=0;
        col_sum[row]=0;
    }
    
    while(scanf("%d",&matrix[row][col])==1){
        col++;
        if (col == n) {
            col = 0;
            row++;
        }
        if (row >= n) break;
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            row_sum[i]+=matrix[i][j];
            col_sum[j]+=matrix[j][i];
            if(i==j)
                diagonal_sum[0]+=matrix[i][j];
            if(j==n-1-i)
                diagonal_sum[1]+=matrix[i][j];
        }
    }
    int target;
    
    target=row_sum[0];
    for(int i=1;i<n;i++){
        if(row_sum[i]!=target||col_sum[i]!=target){
            cols_same=0;
            rows_same=0;
            break;
        }
    }
    if(diagonal_sum[1]!=target||diagonal_sum[0]!=target){
        diagonals_same=0;
    }
    if(diagonals_same&&rows_same&&cols_same)
        printf("True\n");
    else
        printf("False\n");
    
        for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(row_sum);
    free(col_sum);

}