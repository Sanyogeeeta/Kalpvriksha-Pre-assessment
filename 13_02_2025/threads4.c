#include<stdio.h>
#include<pthread.h>

void* computation(void* add){
    long* value=(long*)add;
    for(int i=0;i<100000;i++)
        ++(*value);
    printf("Add: %ld\n",*value);
    return NULL;
}

int main(){

    pthread_t thread1,thread2;
    long value=1;
    computation((void*)&value);
    computation((void*)&value);
    // pthread_create(&thread1,NULL,computation,&value);
    // pthread_create(&thread2,NULL,computation,&value);
    // pthread_join(thread1,NULL);
    // pthread_join(thread2,NULL);
}