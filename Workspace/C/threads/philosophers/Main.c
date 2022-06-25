#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t room;
sem_t chopstick[5];

void *philosopher(void *);
void eat(int);

int main()
{
	int a[5];
	pthread_t tid[5];
	sem_init(&room, 0, 4);

	for (int i = 0; i < 5; i++)
		sem_init(&chopstick[i], 0, 1);

	for (int i = 0; i < 5; i++)
	{
		a[i] = i;
		pthread_create(&tid[i], NULL, philosopher, (void *)&a[i]);
	}

	for (int i = 0; i < 5; i++)
		pthread_join(tid[i], NULL);

	return 0;
}

void *philosopher(void *num)
{
	int pID = *((int *)num);
	sem_wait(&room);

	printf("\nPhilosopher %d has entered room", pID);
	sem_wait(&chopstick[pID]);
	sem_wait(&chopstick[(pID + 1) % 5]);

	printf("\nPhilosopher %d is eating!", pID);
	sleep(2);
	printf("\nPhilosopher %d is finished eating!", pID);

	sem_post(&chopstick[pID]);
	sem_post(&chopstick[(pID + 1) % 5]);
	sem_post(&room);

	return NULL;
}