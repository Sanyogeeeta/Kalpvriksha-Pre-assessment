#include<stdio.h>
#include<stdlib.h>

int main(){
    int rows1,cols1,cols2,rows2;
    scanf("%d %d",&rows1,&cols1);
    scanf("%d %d",&rows2,&cols2);
    int **matrix1;
    int **matrix2;
    int **result;
    if(cols1!=rows2)
        printf("Multiplication is not possible\n");
    else{
        matrix1=(int **)malloc(sizeof(int*)*rows1*cols1);
        matrix2=(int **)malloc(sizeof(int*)*rows2*cols2);
        result=(int **)malloc(sizeof(int*)*rows1*cols2);
        for(int row=0;row<rows1;row++){
            matrix1[row]=(int *)malloc(sizeof(int)*cols1);
            for(int col=0;col<cols1;col++){
                scanf("%d",&matrix1[row][col]);
            }
        }

        for(int row=0;row<rows2;row++){
            matrix2[row]=(int *)malloc(sizeof(int)*cols2);
            for(int col=0;col<cols2;col++){
                scanf("%d",&matrix2[row][col]);
            }
        }    
    
        for(int row=0;row<rows1;row++){
            result[row]=(int *)malloc(sizeof(int)*cols2);
            for(int col=0;col<cols2;col++){
                result[row][col]=0;
            }
        }

        for(int row=0;row<rows1;row++){
            for(int col=0;col<cols1;col++){
            for(int index=0;index<rows1;index++){
                    result[row][col]+=matrix1[row][index]*matrix2[index][col];
            }  
            }
        }

        for(int row=0;row<rows1;row++){
            for(int col=0;col<cols2;col++){
                printf("%d ",result[row][col]);
            }
            printf("\n");
        }
    }

}