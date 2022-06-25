#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAT_SIZE 10
#define MAX_THREADS 100

int matrix1[MAT_SIZE][MAT_SIZE];
int matrix2[MAT_SIZE][MAT_SIZE];
int result[MAT_SIZE][MAT_SIZE];

typedef struct parameters
{
	int x, y;
} args;

void *mult(void *arg)
{
	args *p = arg;

	for (int x = 0; x < MAT_SIZE; x++)
		result[p->x][p->y] += matrix1[p->x][x] * matrix2[x][p->y];

	pthread_exit(0);
}

void b_zero(int matrix[MAT_SIZE][MAT_SIZE])
{
	for (int x = 0; x < MAT_SIZE; x++)
		for (int y = 0; y < MAT_SIZE; y++)
			matrix[x][y] = 0;
}

void fill_matrix(void)
{
	printf("\n --- Initializing Matrix 1 ---\n\n");
	for (int x = 0; x < MAT_SIZE; x++)
		for (int y = 0; y < MAT_SIZE; y++)
			matrix1[x][y] = (rand() * time(NULL)) % 10;

	printf("\n --- Initializing Matrix 2 ---\n\n");
	for (int x = 0; x < MAT_SIZE; x++)
		for (int y = 0; y < MAT_SIZE; y++)
			matrix2[x][y] = rand() % 10;

	printf("\n --- Matrix 1 ---\n\n");
	for (int x = 0; x < MAT_SIZE; x++)
	{
		for (int y = 0; y < MAT_SIZE; y++)
			printf("%5d", matrix1[x][y]);
		printf("\n\n");
	}
	printf(" --- Matrix 2 ---\n\n");
	for (int x = 0; x < MAT_SIZE; x++)
	{
		for (int y = 0; y < MAT_SIZE; y++)
			printf("%5d", matrix2[x][y]);
		printf("\n\n");
	}
}

int main()
{
	b_zero(matrix1);
	b_zero(matrix2);
	b_zero(result);

	pthread_t thread[MAX_THREADS];

	int thread_number = 0;
	args p[MAT_SIZE * MAT_SIZE];

	time_t start = time(NULL);

	for (int x = 0; x < MAT_SIZE; x++)
		for (int y = 0; y < MAT_SIZE; y++)
		{
			p[thread_number].x = x;
			p[thread_number].y = y;

			int status = pthread_create(&thread[thread_number], NULL, mult, (void *)&p[thread_number]);

			if (status != 0)
			{
				printf("Error!");
				exit(0);
			}
			thread_number++;
		}

	for (int i = 0; i < MAT_SIZE * MAT_SIZE; i++)
		pthread_join(thread[i], NULL);

	printf(" ---> Time Elapsed : %.2f Sec\n\n", (double)(time(NULL) - start));
	printf(" --- Multiplied Matrix ---\n\n");
	for (int x = 0; x < MAT_SIZE; x++)
	{
		for (int y = 0; y < MAT_SIZE; y++)
			printf("%5d", result[x][y]);
		printf("\n\n");
	}
}