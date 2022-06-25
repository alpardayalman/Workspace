#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void enqueue(int);
void dequeue(int);
void create();
void check(int);
void display_pqueue();

int pri_que[MAX];
int front,rear;

int main(void){
	int n, ch;

	printf("\n1. Insert");
	printf("\n2. Delete");
	printf("\n3. Display");
	printf("\n4. Exit");

	create();

	while(1){
		printf("\nEnter your choice: ");
		scanf("%d",&ch);

		switch (ch)
		{
		case 1:
			printf("\nEnter value to insert: ");
			scanf("%d",&n);
			enqueue(n);
			break;
		case 2:
			printf("\nEnter value to delete: ");
			scanf("%d",&n);
			dequeue(n);
			break;
		case 3:
			display_pqueue();
			break;
		case 4:
			exit(0);
		default:
			printf("\nInvalid Choice!");
		}
	}
}

void create(){
	front = rear = -1;
}

void enqueue(int data) {
	if (rear >= MAX - 1) {
		printf("\nQueue is full");
		return;
	}
	else if(rear == -1) {
		front++;
		rear++;
		pri_que[rear] = data;
		return;
	}
	else
		check(data);
	rear++;
}

void check(int data){
	int i;
	for (i = 0; i <= rear;i++) {
		if (data >= pri_que[i])
			continue;
		else {
			for (int j = rear + 1; j >i; j--){
				pri_que[j] = pri_que[j - 1];
			}
			break;
		}
	}
	pri_que[i] = data;
}

void display_pqueue(){
	if(rear == -1){
		printf("\nQueue is empty!");
		return;
	}

	for(;front <= rear; front++){
		printf(" %d ",pri_que[front]);
	}

	front = 0;
}

void dequeue(int data) {
	if (rear == -1)
	{
		printf("\n NONONO queue");
		return ;
	}
	for (int i = 0; i <= rear; i++) {
		if (pri_que[i] == data) {
			for (;i<rear;i++) {
				pri_que[i] = pri_que[i+1];
			}
			pri_que[i] = -99;
			rear--;
			if (rear == -1)
				front = -1;
			return;
		}
	}
	printf("\n Data bulunamadi");
}


























