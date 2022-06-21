#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

// sem_t room;
sem_t forks[5];

void *philospher(void *a)
{
	int pid = *(int *)a;
	// sem_wait(&room);
	if (*(int *)a % 2 == 0)
		usleep(2);
	printf("\nPhilosopher %d has entered room", pid);
	sem_wait(&forks[pid]);
	sem_wait(&forks[(pid + 1) % 5]);
	printf("\nPhilosopher %d is eating", pid);
	usleep(2);

	printf("\nPhilosopher %d has finished eating", pid);

	sem_post(&forks[pid]);
	sem_post(&forks[(pid + 1) % 5]);
	// sem_post(&room);
	return NULL;
}

int main(void)
{
	int a[5];
	pthread_t phil[5];
	// sem_init(&room, 0, 4);
	for (int i = 0; i < 5; i++)
		sem_init(&forks[i], 0, 1);
	for (int i = 0; i < 5; i++)
	{
		a[i] = i;
		pthread_create(&phil[i], NULL, philospher, (void *)&a[i]);
	}
	for (int i = 0; i < 5; i++)
		pthread_join(phil[i], NULL);

	for (int i = 0; i < 5; i++)
		sem_close(&forks[i]);
	// sem_close(&room);
	return 0;
}