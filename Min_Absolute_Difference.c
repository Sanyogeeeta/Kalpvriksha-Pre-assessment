#include <stdio.h>
#include<limits.h>

void swap(int* x,int*y){
    int temp=*x;
    *x=*y;
    *y=temp;    
}

void sort(int *arr, int length){
    for (int i = 0; i < length - 1; i++){
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

int abs_diff(int a, int b){
    return a>b?(a-b):(b-a);
}

void min_abs_diff(int arr[], int length){
    sort(arr, length);
    int diff[length];

    int min_diff = INT_MAX;
    for (int i = 0; i < length-1; i++){
        diff[i] = 0;
        diff[i] = abs_diff(arr[i], arr[i + 1]);
        if (diff[i] < min_diff){
            min_diff = diff[i];
        }
    }
    
    int flag=0;
    
    for(int i=0;i<length;i++){
        if(diff[i]==min_diff){
            if(flag==0){
                printf("[%d,%d]",arr[i],arr[i+1]);
                flag=1;
            }
            else 
                printf(",[%d,%d]",arr[i],arr[i+1]);
        }
    }    
}

int main()
{
    int arr[100000];

    int index = 0,value;
    while (scanf("%d", &value) == 1)
    {
        arr[index]= value;
        index++;
        if (getchar() == '\n')
            break;
    }

    min_abs_diff(arr,index);

    return 0;
}
