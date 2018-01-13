#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#define BUFFER_SIZE 5
#define NUM_P 10
#define NUM_C 10

int out = 0;
int in = 0;
int count = 0;
int buffer[BUFFER_SIZE];
sem_t mutex;
sem_t empty;
sem_t full;

void *producer(void *param)
{
	int item, i, index;
	index = (int) param;
	//produce item
	item = (rand() % 100)+1;
	//if there are no empty slot, wait
	sem_wait(&empty);
	//if another thread uses the buffer, wait
	sem_wait(&mutex);
	buffer[in] = item;
	count++;
	printf("in:%d\tproducer[%d] produce : %d\tItem count:%d\n", in, index, item, count);
	fflush(stdout);
	in = (in + 1) % BUFFER_SIZE;
	//release the buffer
	sem_post(&mutex);
	sem_post(&full);
	pthread_exit(NULL);
}

void *consumer(void *param)
{
	int item, i, index;
	index = (int) param;
	//if there are no full slot, wait
	sem_wait(&full);
	sem_wait(&mutex);
	//consume
	item = buffer[out];
	count--;
	printf("out:%d\tconsumer[%d] consume : %d\tItem count:%d\n", out, index, item, count);
	fflush(stdout);
	out = (out+1) % BUFFER_SIZE;
	sem_post(&mutex);
	sem_post(&empty);
	pthread_exit(NULL);
}
int main()
{
	int i,j,c=0;
	pthread_t idp[NUM_P], idc[NUM_C];
	sem_init(&mutex, 0, 1);
	sem_init(&empty, 0, BUFFER_SIZE);
	sem_init(&full, 0, 0);

	for(i = 0;i < NUM_P; i++)
	{
		j = pthread_create(&idp[i], NULL, producer, (void*)i);
		if(j!=0)
		{
			printf("Unable to create producer thread\n");
			return -1;
		}
	}
	for(i = 0;i < NUM_C; i++)
	{
		j = pthread_create(&idc[i],NULL,consumer,(void*)i);
		if(j!=0)
		{
			printf("Unable to create consumer thread\n");
			return -1;
		}
	}
	for(i = 0; i < NUM_P; i++)
	{
		pthread_join(idp[i], NULL);
		pthread_join(idc[i], NULL);
	}
	pthread_exit(NULL);
}
