#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define bool int
struct sNode *max = NULL;

// structure of a stack node
struct sNode
{
    char data;
    struct sNode *next;
};

int peek(struct sNode *top) {
	return (top->data);
}

void push(struct sNode **top_ref,int new_data){
	struct sNode *new_node = (struct sNode*)malloc(sizeof(struct sNode));

	if(new_node == NULL){
		printf("Stack Overflow!\n");
		exit(0);
	}

	new_node->data = new_data;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}

int pop(struct sNode **top_ref){
	char res;
	struct sNode *top;

	if(*top_ref == NULL){
		printf("Stack Overflow!\n");
		exit(0);
	}
	else{
		top = *top_ref;
		res = top->data;
		*top_ref = top->next;
		free(top);
		return res;
	}
}

void print(struct sNode *top){
	printf("\n");

	while (top != NULL)
	{
		printf(" %d ", top->data);
		top = top->next;
	}
}

void myPush(struct sNode **top_ref,int new_data){
	push(top_ref,new_data);
	if(!max || max->data < new_data){
		push(&max,new_data);
	}
}

void myPop(struct sNode **top_ref){
	int popped = pop(top_ref);
	if(max->data == popped){
		pop(&max);
	}
}

int main() {
	struct sNode *main = NULL;
	myPush(&main,6);
	printf("%d\n",peek(max));
	myPush(&main,7);
	printf("%d\n",peek(max));
	myPush(&main,8);
	printf("%d\n",peek(max));
	myPush(&main,5);
	printf("%d\n",peek(max));
	myPush(&main,3);
	printf("%d\n",peek(max));
	myPop(&main);
	printf("%d\n",peek(max));
	myPush(&main,10);
	printf("%d\n",peek(max));
	myPop(&main);
	printf("%d\n",peek(max));
	myPop(&main);
	printf("%d\n",peek(max));

	return 0;
}