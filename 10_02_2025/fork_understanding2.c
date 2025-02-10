#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int main(){
    pthread_t p_id=fork();
    p_id=fork();
    if(p_id==0){
        printf("child process\n");
    }
    else{
        printf("parent process\n");
    }
    
    printf("Hello\n");
    
    return 0;
}