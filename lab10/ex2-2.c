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
int buffer[BUFFER_SIZE];
sem_t mutex;
sem_t empty;
sem_t full;

void *producer(void *param)
{
	int item, i, index;
	index = (int) param;
	for(i = 0;i < BUFFER_SIZE; i++)
	{
		//produce item
		item = i;
		//if there are no empty slot, wait
		sem_wait(&empty);
		//if another thread uses the buffer, wait
		sem_wait(&mutex);
		buffer[in] = item;
		printf("in:%d producer[%d] produce : %d\n",in, index,item);
		fflush(stdout);
		in = (in + 1) % BUFFER_SIZE;
		//release the buffer
		sem_post(&mutex);
		sem_post(&full);
	}
	pthread_exit(NULL);
}

void *consumer(void *param)
{
	int item, i, index;
	index = (int) param;
	for(i = 0;i < BUFFER_SIZE; i++)
	{
		//if there are no full slot, wait
		sem_wait(&full);
		sem_wait(&mutex);
		//consume
		item = buffer[out];
		printf("out:%d consumer[%d] consume : %d\n", out, index, item);
		fflush(stdout);
		out = (out+1) % BUFFER_SIZE;
		sem_post(&mutex);
		sem_post(&empty);
	}
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
	pthread_exit(NULL);
}
