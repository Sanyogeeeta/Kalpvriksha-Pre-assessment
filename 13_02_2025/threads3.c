#include<stdio.h>
#include<pthread.h>

void* add(void* value){
   long* a=(long* )(value);
   (*a)++;
   return NULL;
}

void* subtract(void* value){
    long* a=(long* )(value);
   (*a)--;
   return NULL;
}

int main(){
    long value=1;
    pthread_t thread1;
    pthread_create(&thread1,NULL,add,&value);
    pthread_join(thread1,NULL);
    printf("%ld\n",value);
    pthread_create(&thread1,NULL,subtract,(void*)&value);
    pthread_join(thread1,NULL);
    printf("%ld\n",value);
}