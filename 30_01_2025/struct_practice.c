#include<stdio.h>
#include<stdlib.h>

struct Data{
    char* sentence;
    int** array;
}d;

int main(){
    d.sentence="Hello";
    int rows=3,cols=3;
    
    d.array=malloc(sizeof(int)*rows);
    for(int i=0;i<rows;i++){
        d.array[i]=malloc(sizeof(int)*cols);
        for(int j=0;j<cols;j++){        
            d.array[i][j]=i*rows+j;
        }
    }

    printf("%s\n",d.sentence);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
        printf("%d",d.array[i][j]);
        printf("\n");
    }

    return 0;
}