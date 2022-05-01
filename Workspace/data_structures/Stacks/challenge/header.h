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

void display(Stack *pt);
int pop(Stack **pt);
int peek(Stack *pt);
void push(Stack **pt, int num);
bool isEmpty(Stack *pt);
void insertAtBottom(Stack **top_ref, int item);
void reverse(Stack **top_ref);
void sortedInsert(Stack **start, int a);
void sortStack(Stack **start);
void	print_menu(void);
#endif