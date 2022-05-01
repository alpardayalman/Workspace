#include "header.h"


bool isEmpty(Stack *top){
	return (top == NULL) ? 1:0;
}

void push(Stack **top_ref,int new_data){
	Stack *new_node = (Stack*)malloc(sizeof(Stack));

	if(new_node == NULL){
		printf("Stack Overflow!\n");
		exit(0);
	}

	new_node->data = new_data;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}

int peek(Stack *top) {
	return (top->data);
}

int pop(Stack **top_ref){
	char res;
	Stack *top;

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

void display(Stack *top){
	printf("\n");

	while (top != NULL)
	{
		printf(" %d ", top->data);
		top = top->next;
	}
}


void insertAtBottom(Stack **top_ref, int item){
	if(isEmpty(*top_ref))
		push(top_ref,item);
	else{
		int temp = pop(top_ref);
		insertAtBottom(top_ref,item);
		push(top_ref,temp);
	}
}

void reverse(Stack **top_ref){
	if(!isEmpty(*top_ref)){
		int temp = pop(top_ref);
		reverse(top_ref);
		insertAtBottom(top_ref,temp);
	}
}

void sortedInsert(Stack **start, int a)
{
    if (isEmpty(*start) || a < peek(*start))
    {
        push(start, a);
        return;
    }
    int temp = pop(start);
    sortedInsert(start, a);
    push(start, temp);
}

void sortStack(Stack **start)
{
    if (!isEmpty(*start))
    {
        int a = pop(start);
        sortStack(start);
        sortedInsert(start, a);
    }
}

void	print_menu(void) {
	printf("\n"
	"1 - Siranin basina koy.\n"
	"2 - Siranin basindan sil.\n"
	"3 - Goster.\n"
	"4 - Reverse.\n"
	"5 - Sort.\n"
	"6 - Menu.\n"
	"0 - Cikis yap.\n"
	);
	printf(":: ");
}