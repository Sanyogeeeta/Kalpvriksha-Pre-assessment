#include<stdio.h>
#define MAX 100

void distinct_count_subarray(int array[],int length,int k){
    int distinct_count;
    int left=0,right=left+k;
    while(right<=length){
        int hashmap[MAX]={0};
        distinct_count=0;
        for(int itr=left;itr<right;itr++){
            if(hashmap[array[itr]]==0){
                hashmap[array[itr]]=1;
                distinct_count+=1;
            }
        }
        if(right==length)
            printf("%d",distinct_count);
        else
            printf("%d,",distinct_count);
        left++;
        right++;
    }
}

int main(){
    int array[MAX],index=0,k;

    printf("arr=");
    while(getchar()!='[');
    while(scanf("%d",&array[index])==1){
        index++;
        if(getchar()==']')break;
    }

    printf(",K:");
    scanf("%d",&k);
    printf("[");
    distinct_count_subarray(array,index,k);
    printf("]\n");
    return 0;
}