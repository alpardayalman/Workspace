//Ilk ders konusu.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
int data;
int key;
struct Node *next;
};


struct Node *head = NULL;
struct Node *current = NULL;

void printList(void){
	struct Node *ptr = head;

	printf("\n[ ");

	while(ptr != NULL){
		printf("(%d,%d)", ptr->key, ptr->data);
		ptr = ptr->next;
	}
	printf(" ]");
}

void insertFirst(int key, int data) {
	struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr->key = key;
	ptr->data = data;
	ptr->next = head;
	head = ptr;
}

struct Node *delfirst(void) {
	if(!head)
		return NULL;
	struct Node *ptr = head;
	head = head->next;
	return (ptr);
}

bool isEmpty(void) {
	return head == NULL;
}

int length(void) {
	int length = 0;
	struct Node *ptr = head;
	while (ptr) {
		length++;
		ptr = ptr->next;
	}
	return (length);
}

struct Node *find(int key) {
	struct Node *ret = head;
	while(ret->key != key && ret) {
		ret = ret->next;
	}
	return (ret);
}

struct Node *delete(int key) {
	if(!head)
		return NULL;
	struct Node *ptr = head;
	while(ptr->next) {
		if (ptr->next->key == key) {
			struct Node *a = ptr->next;
			ptr->next = ptr->next->next;
			return a;
		}
		else
			ptr = ptr->next;
	}
	return (NULL);
}

void    swap(struct Node *a, struct Node *b) {
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void sort(void){
	struct Node *current;
	struct Node *next;

	int size = length();
	int k = size;

	for(int i = 0; i<size-1; i++, k--){
		current = head;
		next = head->next;

		for(int j = 1; j<k; j++){
			if(current->data > next->data){
				int temp = current->data;
				current->data = next->data;
				next->data = temp;

				int tempKey = current->key;
				current->key = next->key;
				next->key = tempKey;
			}

			current = current->next;
			next = next->next;
		}
	}
}

//reverse
void reverse(struct Node **head_ref) {
	struct Node *prev = NULL;
	struct Node *current = *head_ref;
	struct Node *next;

	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

int main(){
	insertFirst(1,10);
	insertFirst(2,20);
	insertFirst(3,30);
	insertFirst(4,1);
	insertFirst(5,40);
	insertFirst(6,56);

	printf("Original!\n");
	printList();
	sort();
	printf("Modified!\n");
	printList();
	return 0;
}



