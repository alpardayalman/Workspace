#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void wait(void)
{
	sleep(3);
	printf("Done!\n");
}

int main(void)
{
	pthread_t thread;
	int err = pthread_create(&thread, NULL, wait, NULL);

	if (err)
	{
		printf("An error occurred!: %d", err);
		return 1;
	}

	printf("Waiting for the thread to end...\n");
	pthread_join(thread, NULL);
	printf("Thread ended!\n");

	return 0;
}