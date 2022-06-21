#ifndef _HEAD
#define _HEAD

#define BUFFER_SIZE 4
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include "libft/include/libft.h"
#include <string.h>

typedef struct adj
{
	char *cityName;
	int code;
	int distance;
} Adjacent;

typedef struct Node
{
	char *cityName;
	int code;
	int Distances[81];
	Adjacent **adjacencies;
} City;

City *createCity(char **dist, char **adj);
Adjacent *createAdjList(int size);
int sizeOfArray(char **array);
#endif