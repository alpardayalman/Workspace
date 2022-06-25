#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NO_OF_ELEMENTS 100000000

static long long int sum;
static int arr[MAX_NO_OF_ELEMENTS];

int main()
{
	for (int i = 0; i < MAX_NO_OF_ELEMENTS; i++)
	{
		arr[i] = i + 1;
	}

	clock_t start, end;
	double cpu_time_taken;

	start = clock();

	// summing

	for (int i = 0; i < MAX_NO_OF_ELEMENTS; i++)
	{
		sum += arr[i];
	}

	end = clock();

	cpu_time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("Total sum: %lld\n", sum);
	printf("Time taken: %lf\n", cpu_time_taken);
}