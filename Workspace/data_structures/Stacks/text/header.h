#ifndef _STRUCT
#define _STRUCT

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack_s
{
    char data;
    struct Stack_s *next;
}Stack;
int peek(Stack **pt);
#endif