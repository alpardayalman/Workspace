#include "header.h"

bool isEmpty(Stack **pt) {
	return ((*pt) == NULL);
}

void push(Stack **pt, int data){
	Stack *ptr = (Stack *) malloc (sizeof(Stack));
	ptr->data = data;
	ptr->next = *pt;
	*pt = ptr;
}

int pop(Stack **pt) {
	if (isEmpty(pt))
		exit(EXIT_FAILURE);
	int top = peek(pt);
	Stack *ptr = *pt;
	(*pt) = (*pt)->next;
	free(ptr);
	return (top);
}

int peek(Stack **pt) {
	return ((*pt)->data);
}

void print(Stack **pt) {
	Stack *ptr = *pt;
	while (ptr) {
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
}

void pushbot(Stack **pt, int item) {
	if (isEmpty(pt)) {
		push(pt,item);
		return ;
	}
	else {
		int temp = pop(pt);
		pushbot(pt,item);
		push(pt,temp);
	}
}

void reverse(Stack **pt) {
	if (!isEmpty(pt)) {
		int temp = pop(pt);
		reverse(pt);
		pushbot(pt,temp);
	}
}

void sortAyberk(Stack **pt, int item) {
	if (isEmpty(pt) || item < peek(pt)) {
		push(pt,item);
		return ;
	}
	else {
		int temp = pop(pt);
		sortAyberk(pt, item);
		push(pt, temp);
	}
}

void sortStack(Stack **pt) {
	if (!isEmpty(pt)) {
		int temp = pop(pt);
		sortStack(pt);
		sortAyberk(pt, temp);
	}
}

int main() {
	Stack *top = NULL;
	push(&top,1);
	push(&top,2);
	push(&top,7);
	push(&top,3);
	push(&top,9);
	print(&top);
	sortStack(&top);
	printf("\n");
	print(&top);
	printf("\n");
	reverse(&top);
	print(&top);
	pop(&top);
	printf("\n");
	print(&top);
	return 0;
}