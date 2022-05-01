#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Array data structure.
struct Stack{
	int maxSize;
	int top;
	int *items;
};

struct Stack *newStack(int capacity){
	struct Stack *pt = (struct Stack*)malloc(sizeof(struct Stack));
	pt->maxSize = capacity;
	pt->top = -1;
	pt->items = (int *) malloc(sizeof(int) * capacity);

	return pt;
}

int size(struct Stack *pt) {
	return (pt->top + 1);
}

bool isEmpty(struct Stack *pt) {
	return (pt->top == -1);
}

bool isFull(struct Stack *pt) {
	return (pt->top == pt->maxSize - 1);
}

//is full return .
void push(struct Stack *pt, int num){
	if (isFull(pt)){
		printf("StackOverflow!\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}
	pt->items[++pt->top] = num;
}

int peek(struct Stack *pt) {
	if (isEmpty(pt)) {
		printf("Nothing to peek add something\n");
		exit(EXIT_FAILURE);
	}
	return (pt->items[pt->top]);
}

int pop(struct Stack *pt){
	if (isEmpty(pt)) {
		printf("StackUnderflow!\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}
	return (pt->items[pt->top--]);
}

void display(struct Stack *pt) {
	if (isEmpty(pt)) {
		return;
	}
	int x = peek(pt);
	pop(pt);

	printf("%d ",x);

	display(pt);
	push(pt,x);
}

int main() {
	int initialSize;
	printf("Enter Initial Size: ");
	scanf("%d",&initialSize);

	struct Stack *pt = newStack(initialSize);
	for (int i = 1; i <= 3;i++)
		push(pt,i);

	printf("\nThe top elements is: %d\n",peek(pt));
	printf("Size = %d\n", size(pt));
	//pop(pt);
	if (isEmpty(pt))
		printf("\nStack bostur!\n\n");
	else
		printf("\nStack doludur!\n\n");
	display(pt);
	return 0;
}