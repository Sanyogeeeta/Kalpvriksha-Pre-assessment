#include <stdio.h>

int Inversion_count(int arr[],int index){
int count=0;
    for(int i=0;i<index;i++){
        for(int j=i+1;j<index;j++){
            if(arr[i]>arr[j] &&i<j)
                count++;
        }
    }
    return count;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int arr[100000];
    
    int index=0,value;
    while (scanf("%d", &value) == 1)
    {
        arr[index]= value;
        index++;
        if (getchar() == '\n')
            break;
    }
    
    int count=0;
    count=Inversion_count(arr,index);
    printf("%d\n",count);
    return 0;
}
