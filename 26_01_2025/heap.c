#include<stdio.h>
#include<stdlib.h>

int insertion(int* arr,int level,int value){
    int left=2*level+1;
    int right=2*level+2;
    if(arr[level]==-1){
        arr[level]=value;
        return level;
    }
    if(arr[left]==-1){
        arr[left]=value;
        return left;
    }
    if(arr[right]==-1){
        arr[right]=value;
        return right;
    }
    return insertion(arr,level+1,value);
}

void display(int arr[],int l){
    int i=0;
    printf("%d ",arr[i]);
    while(i<l){
        printf("%d ",arr[2*i+1]);
        printf("%d ",arr[2*i+2]);
        i++;
    }
}

int main(){
    int level=0,value;
    int array[100]={-1};

    while(scanf("%d",&value)){
        level=insertion(array,level,value);
        if(getchar()=='\n')break;
    }

    display(array,level);
    return  0;
}