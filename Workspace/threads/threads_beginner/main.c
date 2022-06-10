#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *worki(void *tid)
{
	long MYid = (long)tid;
	printf("The name of me tread is %lu\n", MYid);
}

int main()
{
	pthread_t tid0;
	pthread_t tid1;
	pthread_t tid2;
	pthread_t *treads[] = {&tid0, &tid1, &tid2};
	for (int i = 0; i < 3; i++)
		pthread_create(treads[i], NULL, worki, (void *)treads[i]);
	pthread_exit(NULL);
	return 0;
}