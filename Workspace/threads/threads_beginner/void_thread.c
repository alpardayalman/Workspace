#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *myThreadFunc(void *vargp)
{
	sleep(2);
	printf("in Thread\n");
	return NULL;
}

int main()
{

	pthread_t thread_id;
	printf("Before thread\n");
	pthread_create(&thread_id, NULL, myThreadFunc, NULL);
	pthread_join(thread_id, NULL);
	printf("After thread\n");
	exit(0);
}