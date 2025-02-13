#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 10

pthread_mutex_t mutex;
pthread_cond_t cond;
int buffer[MAX];
int front = -1, rear = -1;

void* generate_number(void* arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        while ((rear + 1) % MAX == front) {
            printf("Buffer is Full\n");
            pthread_cond_wait(&cond, &mutex);
        }
        int num = rand() % 100;
        buffer[++rear] = num;
        if (front == -1) front = 0;
        printf("Produced: %d\n", num);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void* print_number(void* arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        while (front == -1 || front > rear) {
            printf("Buffer is Empty\n");
            pthread_cond_wait(&cond, &mutex);
        }
        printf("Consumed: %d\n", buffer[front++]);
        if (front > rear) {
            front = rear = -1;
        }
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&thread1, NULL, generate_number, NULL);
    pthread_create(&thread2, NULL, print_number, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}
