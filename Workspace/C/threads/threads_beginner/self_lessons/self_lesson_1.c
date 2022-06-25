#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define EAT 5
#define SLEEP 5
#define DEATH 5
#define SIZE 10

struct philosopher_t
{
	int philosopher_ID;
	time_t time_since_eat;
	int fork_r;
	int fork_l;
	int num_of_time_ate;
	pthread_t *philosopher;
	struct thread_t *thread_main;
};

struct thread_t
{
	int no_of_philosophers;
	time_t time_of_eat;
	time_t time_of_sleep;
	time_t time_of_death;
	time_t start_eat;
	int all_eaten;
	int died;
	pthread_mutex_t ID_lock;
	pthread_mutex_t **forks;
	struct philosopher_t **philosophers;
};

time_t timestamp(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

time_t time_diff(time_t past, time_t present)
{
	return (present - past);
}

void eat(struct philosopher_t *philos)
{
	struct thread_t *main = philos->thread_main;
	pthread_mutex_lock(main->forks[philos->fork_l]);
}

void *work(void *main_struct)
{
	struct philosopher_t *philos = (struct philosopher_t *)main_struct;
	struct thread_t *main = philos->thread_main;
	if (philos->philosopher_ID % 2 == 1)
		usleep(10000);
	while (!main->died)
	{
	}
	return NULL;
}

void philosopher_init(struct thread_t *ret, int no_of_philosophers)
{
	ret->philosophers = (struct philosopher_t **)malloc(sizeof(struct philosopher_t *) * no_of_philosophers);
	ret->forks = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t) * no_of_philosophers);
	for (int i = 0; i < no_of_philosophers; i++)
	{
		ret->forks[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(ret->forks[i], NULL);
		ret->philosophers[i] = (struct philosopher_t *)malloc(sizeof(struct philosopher_t));
		ret->philosophers[i]->time_since_eat = 0;
		ret->philosophers[i]->fork_l = i;
		ret->philosophers[i]->fork_r = (i % no_of_philosophers);
		ret->philosophers[i]->philosopher_ID = i;
		ret->philosophers[i]->philosopher = (pthread_t *)malloc(sizeof(pthread_t));
		ret->philosophers[i]->thread_main = ret;
	}
}

struct thread_t *create(int no_of_philosophers)
{
	struct thread_t *ret = (struct thread_t *)malloc(sizeof(struct thread_t));
	ret->no_of_philosophers = no_of_philosophers;
	ret->time_of_eat = EAT;
	ret->time_of_sleep = SLEEP;
	ret->time_of_death = DEATH;
	ret->died = 0;
	ret->all_eaten = 0;
	pthread_mutex_init(&ret->ID_lock, NULL);
	philosopher_init(ret, no_of_philosophers);
	return (ret);
}

void thread_doer(struct thread_t *main)
{
	for (int i = 0; i < SIZE; i++)
	{
		pthread_create(main->philosophers[i]->philosopher, NULL, &work, (void *)main->philosophers[i]);
		main->philosophers[i]->time_since_eat = timestamp();
	}
	for (int i = 0; i < SIZE; i++)
	{
		pthread_join(*main->philosophers[i]->philosopher, NULL);
		pthread_mutex_destroy(main->forks[i]);
	}
	pthread_mutex_destroy(&main->ID_lock);
}

void action_print(struct thread_t *main, int id, char *string)
{
	pthread_mutex_lock(&(main->ID_lock));
	if (!(main->died))
	{
		printf("%lli ", timestamp() - main->start_eat);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(main->ID_lock));
	return;
}

int main()
{
	struct thread_t *main = create(SIZE);
	thread_doer(main);
	return 1;
}