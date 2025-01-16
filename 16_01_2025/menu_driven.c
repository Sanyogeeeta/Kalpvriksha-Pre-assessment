#include<stdio.h>
enum MENU{
    ADD=1,
    SUB,
    MUL,
    TRANS,
    EXIT
};

void read(int m[100][100],int row,int col){
    printf("Enter elements:");
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            scanf("%d",&m[r][c]);
        }
    }
}

void print(int m[100][100],int row,int col){
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            printf("%d ",m[r][c]);
        }
        printf("\n");
    }
}

void transpose(int m[100][100],int row,int col){
    for(int c=0;c<col;c++){
        for(int r=0;r<row;r++){
            printf("%d ",m[r][c]);
        }
        printf("\n");
    }
}

void add_mat(int m1[100][100],int m2[100][100],int m[100][100],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            m[i][j]=m1[i][j]+m2[i][j];
        }
    }
}

void sub_mat(int m1[100][100],int m2[100][100],int m[100][100],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            m[i][j]=m1[i][j]-m2[i][j];
        }
    }
}

void mul_mat(int m1[100][100],int m2[100][100],int m[100][100],int r1,int c2,int c1){
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            m[i][j]=0;
            for(int k=0;k<c1;k++){
                m[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
}

int main(){
   int choice;
    int m1[100][100],m2[100][100],m[100][100];
    int r1,c1,c2,r2;

    printf("1-Add\n2-Sub\n3-Multiply\n4-Divide\n");
    do{
        printf("Enter choice");
        scanf("%d",&choice);
        switch(choice){
            case ADD:
                scanf("%d %d",&r1,&c1);
                scanf("%d %d",&r2,&c2);
                read(m1,r1,c1);
                read(m2,r2,c2);
               if(r1==r2&&c1==c2){
                    add_mat(m1,m2,m,r1,c1);
                    print(m,r1,c1);
               }
               else
                    printf("Not possible");
                break;
            case SUB:
                scanf("%d %d",&r1,&c1);
                scanf("%d %d",&r2,&c2);
                read(m1,r1,c1);
                read(m2,r2,c2);
               if(r1==r2&&c1==c2){
                    sub_mat(m1,m2,m,r1,c1);
                print(m,r1,c1);}
                else
                    printf("Not possible");
                break;
            case MUL:
                scanf("%d %d",&r1,&c1);
                scanf("%d %d",&r2,&c2);
                read(m1,r1,c1);
                read(m2,r2,c2);
               if(r2==c1){
                    mul_mat(m1,m2,m,r1,c2,c1);
                print(m,r1,c1);
               }
            break;
            case TRANS:
                scanf("%d %d",&r1,&c1);
                read(m1,r1,c1);
                transpose(m1,r1,c1);
            break;
            case EXIT:
                return 0;
        }
    }while(choice!=5);
    return 0;
}