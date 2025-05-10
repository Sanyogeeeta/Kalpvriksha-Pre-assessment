#include<stdio.h>
#include<string.h>
#define MAX 128

int hash_function(char c){
    return (int)c;
}

int consecutive_sequence(char str[],int k){
    int distinct_count=0,max_length=0;
    int length=strlen(str);
    int left=0,right=0;
    int hashmap[MAX]={0};

    while(right<length){  

        int index=hash_function(str[right]);
        if(hashmap[index]==0){
            distinct_count+=1;
        }
        hashmap[index]++;
        right++;

        while(distinct_count>k){
            int left_index=hash_function(str[left]);
            hashmap[left_index]--;
            if(hashmap[left_index]==0){
                distinct_count--;
            }
            left++;
        }

        if(distinct_count==k){
            if(max_length<(right-left)){
                max_length=right-left;
            }
        }
    }
    return max_length;
}

int main(){

    char str[MAX];
    int k;

    printf("s=");
    scanf("%s",str);

    printf("k:");
    scanf("%d",&k);
    printf("Output:%d\n",consecutive_sequence(str,k));
    return 0;
}