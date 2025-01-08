#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char str[10][101][50];
    int rows,cols,count=0;
    char name[50],long_str[50]="";

    printf("Enter the number of rows:");
    scanf("%d",&rows);
    printf("Enter the number of columns:");
    scanf("%d",&cols);

    printf("Enter the names:\n");
    getchar();
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("Name at (%d,%d):",i,j);
            scanf("%49[^\n]s",name);
            getchar();
            if(strlen(name)>strlen(long_str))
                strcpy(long_str,name);
            if(name[0]=='A'||name[0]=='E'||name[0]=='I'||name[0]=='O'||name[0]=='U'||name[0]=='a'||name[0]=='e'||name[0]=='i'||name[0]=='o'||name[0]=='u')
                count+=1;
            strcpy(str[i][j],name);
        }

    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%s\t",str[i][j]);
        }
        printf("\n");
    }  
    printf("\n\nNumber of names starting witha vowels:%d\n",count);
    printf("The longest name:%s\n",long_str);
    return 0;
}