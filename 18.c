#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define MAX_ITERATIONS 50

sem_t empty;    // Semaphore to track empty slots in the buffer
sem_t full;     // Semaphore to track filled slots in the buffer
pthread_mutex_t mutex;  // Mutex for mutual exclusion
int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int iterations = 0;

void* producer(void* arg) {
    int item = 1;

    while (iterations < MAX_ITERATIONS) {
        sleep((int)arg);  // Simulate time taken to produce an item

        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        // Produce item and add it to the buffer
        buffer[in] = item;
        printf("Produced item %d at position %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;
        item++;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);

        iterations++;
    }

    return NULL;
}

void* consumer(void* arg) {
    while (iterations < MAX_ITERATIONS) {
        sleep((int)arg);  // Simulate time taken to consume an item

        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        // Consume item from the buffer
        int item = buffer[out];
        printf("Consumed item %d from position %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        iterations++;
    }

    return NULL;
}

int main() {
    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Input for sleep times
    int producer_sleep, consumer_sleep;
    printf("Enter sleep time for producer (in seconds): ");
    scanf("%d", &producer_sleep);
    printf("Enter sleep time for consumer (in seconds): ");
    scanf("%d", &consumer_sleep);

    // Create producer and consumer threads
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, (void*)&producer_sleep);
    pthread_create(&consumer_thread, NULL, consumer, (void*)&consumer_sleep);

    // Wait for the threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Destroy semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
return 0;
}
