#include<stdio.h>
#define MAX 1000

void smallest_subarray(int hashmap[],int array[],int length){
    int max_frequency=0, start_index=0;
    for(int itr=0;itr<length;itr++){
        if(max_frequency<hashmap[array[itr]]){
            max_frequency=hashmap[array[itr]];
            start_index=itr;
        }
    }
    int count=1;
    for(int itr= start_index+1;itr<length;itr++){
        if(array[itr]==array[start_index]){
            count++;
            if(count==hashmap[array[itr]]){
                printf("Output:[%d,%d]",start_index,itr);
                return;
            }
        }        
    }
}
int main(){
    int array[MAX],index=0;
    int hashmap[MAX]={0};
    while(getchar()!='[');
    while(scanf("%d",&array[index])==1){
        hashmap[array[index]]+=1;
        index++;
        if(getchar()==']')break;
    }

    smallest_subarray(hashmap,array,index);
    return 0;
}