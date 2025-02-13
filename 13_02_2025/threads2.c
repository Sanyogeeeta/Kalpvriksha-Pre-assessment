#include<stdio.h>
#include<pthread.h>

void* computation(void* add){
    long* value=(long*)add;
    ++(*value);
    printf("Add: %ld\n",*value);
    return NULL;
}

int main(){
    long add=1;
    printf("Add: %ld\n",add);
    pthread_t thread;
    pthread_create(&thread,NULL,computation,&add);
    pthread_join(thread,NULL);

    printf("Add: %ld\n",add);
    return 0;
}