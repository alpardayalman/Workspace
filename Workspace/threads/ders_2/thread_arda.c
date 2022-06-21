#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define MAX_T 4
#define MAX_E 100000000

static long long int sum;
static int arr[MAX_E];

typedef struct
{
	int num;
} arg_t;

void *work_b(void *arg)
{
	arg_t *argument = (arg_t *)arg;
	int end = argument->num * (MAX_E / MAX_T);
	int start = end - (MAX_E / MAX_T);

	long long int thread_create = 0;
	for (int i = start; i < end; i++)
		thread_create += arr[i];
	sum += thread_create;
	return NULL;
}

int main(void)
{
	for (int i = 0; i < MAX_E; i++)
		arr[i] = i + 1;

	pthread_t pids[MAX_T];
	arg_t arg_arr[MAX_T];

	clock_t start, end;
	start = clock();

	for (int i = 0; i < MAX_T; i++)
	{
		arg_arr[i].num = i + 1;
		pthread_create(&pids[i], NULL, work_b, &arg_arr[i]);
	}

	for (int i = 0; i < MAX_T; i++)
		pthread_join(pids[i], NULL);

	end = clock();

	double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Sum of array = %llu time = %f\n", sum, time_taken);
	return 0;
}