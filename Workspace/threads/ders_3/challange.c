#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct phil
{
	int no;
};

void *eat(void *a)
{
}

int main()
{
	pthread_t philosoph_1;
	pthread_t philosoph_2;
	struct phil a;
	pthread_create(&philosoph_1, NULL, eat, (void *)a);
}