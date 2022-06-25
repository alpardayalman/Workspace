#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_NO_OF_ELEMENTS 100000000
#define MAX_NO_OF_THREADS 4

typedef struct arg_data
{
	int thread_number;
} arg_data;
static int arr[MAX_NO_OF_ELEMENTS];
static long long int sum;

// worker
void *worker_sum(void *arg)
{
	arg_data *currentThreadData = (arg_data *)arg;
	printf("Current thread no is: %d\n", currentThreadData->thread_number);

	int endPart = (currentThreadData->thread_number) * (MAX_NO_OF_ELEMENTS / MAX_NO_OF_THREADS);
	int startPart = endPart - (MAX_NO_OF_ELEMENTS / MAX_NO_OF_THREADS);

	printf("Thread-%d will calculate the sum %d to %d\n", currentThreadData->thread_number, arr[startPart], arr[endPart - 1]);

	long long int current_thread_sum = 0;

	for (int i = startPart; i < endPart; i++)
	{
		current_thread_sum += arr[i];
	}

	sum += current_thread_sum;
	return NULL;
}

// main
int main()
{
	for (int i = 0; i < MAX_NO_OF_ELEMENTS; i++)
	{
		arr[i] = i + 1;
	}

	pthread_t id[MAX_NO_OF_THREADS];

	arg_data arg_arr[MAX_NO_OF_THREADS];

	int no_of_threads = MAX_NO_OF_THREADS;
	printf("Creating %d number of threads...\n", no_of_threads);

	clock_t start, end;
	double cpu_time_taken;

	start = clock();

	for (int thread_no = 1; thread_no <= MAX_NO_OF_THREADS; thread_no++)
	{
		arg_arr[thread_no - 1].thread_number = thread_no;
		pthread_create(&id[thread_no - 1], NULL, worker_sum, &arg_arr[thread_no - 1]);
	}

	for (int i = 1; i <= MAX_NO_OF_THREADS; i++)
		pthread_join(id[i - 1], NULL);

	end = clock();

	cpu_time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("Total sum: %lld\n", sum);
	printf("Time taken: %lf\n", cpu_time_taken);

	return 0;
}
