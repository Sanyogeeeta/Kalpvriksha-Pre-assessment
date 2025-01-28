#include <stdio.h>

void swap(int *x,int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void sort(int * arr,int length){
    for(int i=0;i<length-1;i++){
        int swapped=0;
        for(int j=0;j<length-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapped=1;
            }
        }
        if(swapped==0)break;
    }
}

int match_pair(int players[],int trainers[],int players_len,int trainers_len){
    int count=0;
    int i=0,j=0;
    
    while(i<players_len && j<trainers_len){
        if(players[i]<=trainers[j]){
            i++;
            j++;
            count++;
        }else{
            j++;
        }
    }
    return count;
}
               
int main() {
    
    int players[100000],trainers[100000];
    int value;            
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int players_index=0;
    while (scanf("%d", &value) == 1)
    {
        players[players_index]= value;
        players_index++;
        if (getchar() == '\n')
            break;
    }
    
    int trainers_index=0;
    while (scanf("%d", &value) == 1)
    {
        trainers[trainers_index]= value;
        trainers_index++;
        if (getchar() == '\n')
            break;
    }
    
    sort(players,players_index);
    sort(trainers,trainers_index);
    
    int match=match_pair(players,trainers,players_index,trainers_index);
    printf("%d\n",match);
    return 0;
}
