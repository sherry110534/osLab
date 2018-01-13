#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_P	10
#define NUM_C	10
#define BUF_SIZE	5
sem_t fill;
sem_t empty;
sem_t mutex;

int in, out, count;

void *producer(void *arg){
	sem_wait(&empty);
	sem_wait(&mutex);
	//put item
	count++;
	printf("Item count:%d\n", count);
	sem_post(&mutex);
	sem_post(&fill);
	pthread_exit(NULL);
}

void *comsumer(void *arg){
	sem_wait(&fill);
	sem_wait(&mutex);
	//pop item
	count--;
	printf("Item count:%d\n", count);
	sem_post(&mutex);
	sem_post(&empty);
	pthread_exit(NULL);
}

int main(void){
	sem_init(&fill, 0, 0);
	sem_init(&empty, 0, BUF_SIZE-1);
	sem_init(&mutex, 0, 1);
	pthread_t pro[NUM_P], com[NUM_C];
	int i = 0;
	for(i = 0; i < NUM_P; i++){
		pthread_create(&pro[i], NULL, (void*)producer, NULL);
	}
	for(i = 0; i < NUM_C; i++){
		pthread_create(&com[i], NULL, (void*)comsumer, NULL);
	}
	pthread_exit(NULL);
}
