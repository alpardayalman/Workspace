#ifndef _HEAD
#define _HEAD

#define BUFFER_SIZE 4
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include "libft/include/libft.h"
#include <string.h>

typedef struct Node
{
	char *cityName;
	int code;
	int adjDistances[81];
} City;

City *createCity(char *code, char *name);

#endif