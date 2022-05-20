#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define bool int
int max = INT_MIN;
int min = INT_MAX;
// structure of a stack node
struct sNode
{
    char data;
    struct sNode *next;
};

void push(struct sNode **top_ref, int new_data);
int pop(struct sNode **top_ref);
bool isEmpty(struct sNode *top);
void print(struct sNode *top);
void edge(struct sNode **top);
int	peek(struct sNode *top);
void reverse(struct sNode **top_ref);
int peek(struct sNode *top) {
	return (top->data);
}

// void insertAtBottom(struct sNode **top_ref, int item){
// 	if(isEmpty(*top_ref))
// 		push(top_ref,item);
// 	else{
// 		int temp = pop(top_ref);
// 		insertAtBottom(top_ref,item);
// 		push(top_ref,temp);
// 	}
// }

// void reverse(struct sNode **top_ref){
// 	if(!isEmpty(*top_ref)){
// 		int temp = pop(top_ref);
// 		// reverse(top_ref);
// 		insertAtBottom(top_ref,temp);
// 	}
// }

void insertAtBottom(struct sNode **top_ref, int item){
	if(isEmpty(*top_ref))
		push(top_ref,item);
	else{
		int temp = pop(top_ref);
		insertAtBottom(top_ref,item);
		push(top_ref,temp);
	}
}

void reverse(struct sNode **top_ref){
	if(!isEmpty(*top_ref)){
		int temp = pop(top_ref);
		reverse(top_ref);
		insertAtBottom(top_ref,temp);
	}
}

void anti_reverse(struct sNode **top_ref){
	if(!isEmpty(*top_ref)){
		int temp = pop(top_ref);
		// reverse(top_ref);
		insertAtBottom(top_ref,temp);
	}
}

void full_reverse(struct sNode **top_ref){
	reverse(top_ref);
	anti_reverse(top_ref);
	reverse(top_ref);
}

bool isEmpty(struct sNode *top){
	return (top == NULL) ? 1:0;
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

void edge(struct sNode **top) {
	struct sNode *pt = *top;
	max = INT_MIN;
	min = INT_MAX;
	while (pt)
	{
		if (pt->data > max)
			max = pt->data;
		if (pt->data < min)
			min = pt->data;
		pt = pt->next;
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

// Sorting
// void sortedInsert(struct sNode **start, int a)
// {
//     if (isEmpty(*start) || a > peek(*start))
//     {
//         push(start, a);
//         return;
//     }
//     int temp = pop(start);
//     sortedInsert(start, a);
//     push(start, temp);
// }

// void sortStack(struct sNode **start)
// {
//     if (!isEmpty(*start))
//     {
//         int a = pop(start);
//         sortStack(start);
//         sortedInsert(start, a);
//     }
// }

int main(){
	struct sNode *s = NULL;

    push(&s, 4);
    push(&s, 20);
    push(&s, 2);
    push(&s, 1);
	push(&s,-1);
	push(&s,10);

    printf("\n Original Stack ");
    print(s);
    full_reverse(&s);
    printf("\n Reversed Stack ");
    print(s);
    return 0;
}
