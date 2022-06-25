#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct philo
{
	int tID;
	time_t eat_start_time;
	time_t eat_end_time; // en son yedikleri saniye - su anki saniye > die;
} philosopher;

typedef struct chopstick
{
	pthread_mutex_t lock;
} chopstick;

typedef struct allPhilo
{
	pthread_mutex_t id_lock;
	int sleep;
	int die;
	int eat;
	int no_of_philosophers;
	int no_of_eat;
	chopstick **allChopsticks;
	philosopher **allPhilos;
} allPhilo;

void *work(void *philosopher)
{
	allPhilo *decoy = (allPhilo *)philosopher;
	pthread_mutex_lock(&decoy->id_lock);
	static int Thread_ID = 0;
	decoy->allPhilos[Thread_ID]->tID = Thread_ID;
	printf("thread ID %d\n", decoy->allPhilos[Thread_ID]->tID);
	Thread_ID++;
	pthread_mutex_unlock(&decoy->id_lock);
	return NULL;
}

int main(int ac, char **av) // no of phil, time to die, time to eat, time to sleep, [no of eat].
{
	allPhilo *philosophs = malloc(sizeof(allPhilo));
	philosophs->sleep = atoi(av[4]);
	philosophs->eat = atoi(av[3]);
	philosophs->die = atoi(av[2]);
	philosophs->no_of_philosophers = atoi(av[1]);
	if (av[5])
		philosophs->no_of_eat = atoi(av[5]);
	else
		philosophs->no_of_eat = -1;

	philosophs->allChopsticks = malloc(sizeof(chopstick *) * philosophs->no_of_philosophers);
	philosophs->allPhilos = malloc(sizeof(philosopher *) * philosophs->no_of_philosophers);
	pthread_t tid[philosophs->no_of_philosophers];
	pthread_mutex_init(&philosophs->id_lock, NULL);
	for (int i = 0; i < philosophs->no_of_philosophers; i++)
	{
		philosophs->allChopsticks[i] = malloc(sizeof(chopstick));
		pthread_mutex_init(&philosophs->allChopsticks[i]->lock, NULL);
		philosophs->allPhilos[i] = malloc(sizeof(philosopher));
		pthread_create(&tid[i], NULL, work, (void *)philosophs);
	}
	for (int a = 0; a < philosophs->no_of_philosophers; a++)
	{
		pthread_join(tid[a], NULL);
	}
	return 0;
}