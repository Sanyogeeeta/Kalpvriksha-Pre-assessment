#include<stdio.h>
#include<string.h>

#define MAX 100

enum MENU{TYPE=1,UNDO,REDO,EXIT};

char pop(char c[],int *top){
    return c[(*top)--];
}

void push(char s[],int* top,char c){
    s[++(*top)]=c;
}

void undo(char str[],char s1[],char s2[],int* top1,int* top2){
    int len=strlen(str)-1;
    if(len>0){
    push(s1,top1,str[len]);
    str[len]='\0';
    }
    else{
        printf("Nothing to undo\n");
    }
}

void redo(char str[],char s1[],char s2[],int* top1,int* top2){
    int len=strlen(str);
    if(*top1!=-1){
    char c=pop(s1,top1);
    push(s2,top2,c);
    str[len]=c;
    str[len+1]='\0';
    }
    else{
        printf("Nothing to redo\n");
    }
}

char type(char str[],char c){
    int len=strlen(str);
    str[len]=c;
    str[len+1]='\0';
}

int main(){
    char s1[MAX],s2[MAX],c;
    int choice=0,top1=-1,top2=-1;
    char str[MAX]="";

    while(choice!=EXIT){
        scanf("%d",&choice);
        getchar();

        switch(choice){
            case TYPE:
            scanf("%c",&c);
            type(str,c);
            printf("%s",str);
            break;
            case UNDO:
            undo(str,s1,s2,&top1,&top2);
            printf("%s\n",str);
            break;
            case REDO:
            redo(str,s1,s2,&top1,&top2);
            printf("%s\n",str);
            break;
            case EXIT:
            return 0;
            default:
            printf("Invalid!\n");
        }
    }
    return 0;
}