#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char str[500];
    int matrix[10][10];
    int row=0,col=0,cols=0;
    fgets(str,sizeof(str),stdin);
    int len=strlen(str);
    char *ptr=str;
    int num;

    while(*ptr){
        if(isdigit(*ptr)){
            sscanf(ptr,"%d",&num);
            matrix[row][col++]=num;
            while(isdigit(*ptr))
            ptr++;
        }
        else if(*ptr==','){
            cols=col;
            col=0;
            row+=1;
        }
        ptr++;
    }
    
    int top=0,bottom=row,left=0,right=col-1;
    printf("[");
    while(top<=bottom && left<=right)
    {
        for(int i=left;i<=right;i++)
        {
         if(top==0&& i==0)
             printf("%d",matrix[top][i]);
         else
             printf(" %d",matrix[top][i]);
         }
         top++;
         for(int i=top;i<=bottom;i++)
             printf(" %d",matrix[i][right]);
         right--;
         if(top<=bottom){
              for(int i=right;i>=left;i--)
                  printf(" %d",matrix[bottom][i]);
              bottom--;
         }
         if(left<=right){
              for(int i=bottom;i>=top;i--)
                  printf(" %d",matrix[i][left]);
              left++;
         }

     }
    printf("]\n");
    return 0;
        
}