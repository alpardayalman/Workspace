#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

pthread_mutex_t lock;
int j;

void work()
{
	pthread_mutex_lock(&lock);
	int i = 0;
	j++;

	while (i < 5)
	{
		printf("%d", j);
		sleep(1);
		i++;
	}

	printf("... Done!\n");
	pthread_mutex_unlock(&lock);
}

int main()
{
	pthread_t t1, t2;

	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("Mutex initialization failed!");
		return 1;
	}

	j = 0;

	pthread_create(&t1, NULL, work, NULL);
	pthread_create(&t2, NULL, work, NULL); // supersonic

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return 0;
}