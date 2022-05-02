
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
	int data;
	struct Node* previous;
}*node_ptr;

node_ptr front = NULL;
node_ptr rear = NULL;

bool is_empty(){
	return front == NULL;
}

void display_front(){
	if(is_empty()){
		printf("\nThe queue is empty!\n");
		return;
	}

	printf("\n[%c]\n",front->data);
}

void display_rear(){
	if(is_empty()){
		printf("\nThe queue is empty!\n");
		return;
	}

	printf("\n[%c]\n",rear->data);
}

bool enqueue(int value){
	node_ptr item = (node_ptr) malloc(sizeof(struct Node));
	if(item == NULL)
		return false;

	item->data = value;
	item->previous = NULL;

	if(rear == NULL){
		front = rear = item;
	}
	else{
		rear->previous = item;
		rear = item;
	}

	return true;
}

bool dequeue(){
	node_ptr item = front;
	if (front == NULL ){
		return false;
	}
	else if (front == rear) {
		front = NULL;
		rear = NULL;
		free(item);
		return false;
	}
	else {
		front = front->previous;
		free(item);
	}
	return true;
}

void display(){
	if(is_empty()){
		printf("\nThe queue is empty!\n");
		return;
	}

	node_ptr temp = front;

	while(temp){
		printf("%c",temp->data);
		temp = temp->previous;
	}

	printf("\n");
}

bool del() {
	if(is_empty()){
		printf("\nThe queue is empty!\n");
		return false;
	}
	node_ptr temp = front;
	node_ptr dump = NULL;
	while(temp){
		dump = temp->previous;
		free(temp);
		temp = dump;
	}
	front = NULL;
	return is_empty();
}

int main(){
	int option = 0;
	char value = 0;

	do{
		printf("\nQUEUE Menu\n"
		"\n1. Is Empty"
		"\n2. Enqueue"
		"\n3. Dequeue"
		"\n4. Show Front"
		"\n5. Show Rear"
		"\n6. Display Elements"
		"\n7. Clear Queue"
		"\n\n0. Exit\n\n");

		printf("Option: ");
		scanf("%d",&option);

		switch (option)
		{
			case 1:
				printf(is_empty() ? "\nTrue\n":"\nFalse\n");
				break;
			case 2:
				printf("\nInsert a char value to enqueue: ");
				scanf(" %c",&value);
				printf(enqueue(value) ? "\nEnqueued :)\n" : "\nSomething went wrong :(\n");
				break;
			case 3:
				printf(dequeue() ? "\nDequeued :)\n" : "\nSomething went wrong :(\n");
				break;
			case 4:
				display_front();
				break;
			case 5:
				display_rear();
				break;
			case 6:
				display();
				break;
			case 7:
				printf(del() ? "\nCleared :)\n" : "\nSomething went wrong :(\n");
				break;

			default:
				printf("\nInvalid Option!\n");
				break;
		}
	}while (option != 0);

	return 0;
}