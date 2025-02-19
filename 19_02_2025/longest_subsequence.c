#include<stdio.h>
#define MAX 1000

int consecutive_sequence(int hashmap[],int arr[],int length){
    int count,max_count=0;
    for(int i=0;i<length;i++){
        int initial=arr[i];
        count=0;
        int temp=arr[i];
        if (hashmap[temp - 1] == 0){
            while(hashmap[temp]==1){
                count+=1;
                temp+=1;
            }
            //count+=1;
            if(max_count<count)
                max_count=count;
        }
    }
    return max_count;
}

int main(){

    int arr[MAX],index=0,hashmap[MAX]={0};

    while(getchar()!='[');
    while(scanf("%d",&arr[index])==1){
        hashmap[arr[index]]=1;
        index++;
        if(getchar()==']')break;
    }

    printf("Output:%d\n",consecutive_sequence(hashmap,arr,index));
    return 0;
}