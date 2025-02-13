#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int count= 0;
void* add();
/* DO NOT CHANGE ABOVE CODE */

int main() {
  int input;
  scanf("%d", &input);
  /* Enter your code here. */
  /* Hint:	1. Use add function to increment the count using  threads that will call add() method internally.
  			   Do not use count variable directely.  
          	2. Wait for all threads to finish. */
    
  int threads=input/100000;
  pthread_t p[threads];
  for(int i=0;i<threads;i++){
      pthread_create(&p[i],NULL,add,NULL);
  }
  for(int i=0;i<threads;i++){
      pthread_join(p[i],NULL);
  }
  printf("%d", count);
  return 0;
}

/* DO NOT CHANGE BELOW CODE */
void* add(){
  for(int i=0; i<100000; i++){
    count+=1;
  }
  return NULL;
}