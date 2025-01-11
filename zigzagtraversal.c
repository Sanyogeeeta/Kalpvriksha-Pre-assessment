#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int rows,cols,k=0;
    char str[200];
    char matrix[100][100];
    scanf("%d %d",&rows,&cols);
    getchar();
    scanf("%[^\n]s",str);
    int len=strlen(str);
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            while(str[k]=='"')k++;
            matrix[i][j]=str[k];
            k++;
        }
    }
    for(int i=0;i<rows;i++){
        if(i%2==0){
            for(int j=0;j<cols;j++)
                printf("%c ",matrix[i][j]);
            printf("\n");
        }
        else{
            for(int j=cols-1;j>=0;j--)
                printf("%c ",matrix[i][j]);
            printf("\n");
        }
    }
}