#include <stdio.h>
#include <string.h> // For strcpy
#include<ctype.h>

int main() {
   int row=0,col=0,cols,rows;
   char buff[1000];
    char str[100][100][100]; // Array to hold input with null terminators
    char temp[100];
    char* ptr=buff;
    fgets(buff,sizeof(buff),stdin);

    while(*ptr){
        if(isalpha(*ptr)){
            sscanf(ptr,"%[^\",]",temp);
            strcpy(str[row][col],temp);
            col++;
            while(isalpha(*ptr))
            ptr++;
        }
        else if(*ptr==']'){
            if(col>0){
            cols=col;
            col=0;
            row+=1;
            }
        }
        ptr++;
    }
    rows=row;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%s\n",str[i][j]);
        }
    }

    return 0;
}