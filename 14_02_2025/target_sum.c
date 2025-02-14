#include<stdio.h>
#define MAX 10000

typedef struct hashmap{
    int key;
    long int value;
}hashmap;

long int hash_function(long int key){
    return key%MAX;
}

void insert(hashmap* h,int* index,long int value){
    int key=hash_function(value);
    while (h[key].value != 0) {
        key = (key + 1) % MAX;
    }
    h[key].key=++(*index);
    h[key].value=value;
}

void target_sum(hashmap h[],int target){
    for(int i=0;i<MAX;i++){
        if(h[i].value!=0){
            long int rem=target-h[i].value;
            int key=hash_function(rem);
            while (h[key].value != 0) {
                if (h[key].value == rem && h[key].key != h[i].key) {
                    printf("output: [%d, %d]\n", h[i].key, h[key].key);
                    return;
                }
                key = (key + 1) % MAX;
            }
        }
    }
}

int main(){
    long int target,value;
    int index=-1;
    hashmap h[MAX]={0};
    while(getchar()!='[');
    while(scanf("%ld",&value)==1){
        insert(h,&index,value);
        if(getchar()==']')break;
    }
    
    printf("Enter target:");
    scanf("%ld",&target);
    target_sum(h,target);
}