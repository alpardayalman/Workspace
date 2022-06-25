#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_ITEM 5
#define BUFFER_SIZE 5

sem_t empty;
sem_t full;
pthread_mutex_t mutex;
int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

void *producer(void *pNo)
{
	// sem_wait(&empty);
	int item;
	for (int i = 0; i < MAX_ITEM; i++)
	{
		item = rand() % 10;
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		sleep(1);
		buffer[in] = item;
		printf("Producer %d: Insert Item %d at %d\n", *((int *)pNo), buffer[in], in);
		in = (in + 1) % BUFFER_SIZE;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
	// sem_post(&full);
}

void *consumer(void *cNo)
{
	// sem_wait(&full);

	for (int i = 0; i < MAX_ITEM; i++)
	{
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		sleep(1);

		int item = buffer[out];
		printf("Consumer %d: Remove Item %d from %d\n", *((int *)cNo), item, out);
		out = (out + 1) % BUFFER_SIZE;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
	// sem_post(&empty);
}

int main()
{
	pthread_t prod[5], con[5];
	pthread_mutex_init(&mutex, NULL);
	sem_init(&empty, 0, BUFFER_SIZE);
	sem_init(&full, 0, 0);

	int a[5] = {1, 2, 3, 4, 5};

	for (int i = 0; i < 5; i++)
	{
		pthread_create(&prod[i], NULL, (void *)producer, (void *)&a[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		pthread_join(prod[i], NULL);
	}

	for (int i = 0; i < 5; i++)
	{
		pthread_join(con[i], NULL);
	}

	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);
}
