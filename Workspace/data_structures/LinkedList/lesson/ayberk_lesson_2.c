// C ile K node reverse.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *reverse(struct Node *head, int k){
	if(!head)
		return NULL;

	struct Node *current = head;
	struct Node *next = NULL;
	struct Node *prev = NULL;
	int count = 0;

	while(current != NULL && count < k){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	if(next != NULL)
		head->next = reverse(next,k);

	return prev;
}

void push(struct Node **head_ref, int new_data){
	struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node *node){
	while(node != NULL){
		printf("%d ", node->data);
		node = node->next;
	}
}

int main(void){
	struct Node *head = NULL;
	for(int i = 0; i<10; i++){
		push(&head,i);
	}

	printf("Before Action!\n");
	printList(head);
	head = reverse(head,3);
	printf("\nAfter Action!\n");
	printList(head);

	return 0;
}