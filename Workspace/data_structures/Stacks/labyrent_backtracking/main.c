#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
	int data;
	struct Stack *next;
} Stack;

bool isEmpty(Stack *top)
{
	return (top == NULL ? true : false);
}

Stack *create(int new_data)
{
	Stack *new_node = (Stack *)malloc(sizeof(Stack));
	new_node->data = new_data;
	new_node->next = NULL;
	return (new_node);
}

void push(Stack **top_ref, int new_data)
{
	Stack *new_node = create(new_data);

	new_node->data = new_data;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}

int peek(Stack *top)
{
	return (top->data);
}

int pop(Stack **top_ref)
{
	char res;
	Stack *top;
	Stack *a = *top_ref;
	if (a == NULL)
	{
		printf("hata\n");
		exit(0);
	}
	if (*top_ref == NULL)
	{
		printf("Stack Overflow!\n");
		exit(0);
	}
	else
	{
		top = *top_ref;
		res = top->data;
		*top_ref = top->next;
		free(top);
		return res;
	}
}

void display(Stack *top)
{
	printf("\n");
	int i = 0;
	while (top != NULL)
	{
		printf("%d = %c \n", i++, top->data);
		top = top->next;
	}
}

void insertAtBottom(Stack **top_ref, int item)
{
	if (isEmpty(*top_ref))
		push(top_ref, item);
	else
	{
		int temp = pop(top_ref);
		insertAtBottom(top_ref, item);
		push(top_ref, temp);
	}
}

void reverse(Stack **top_ref)
{
	if (!isEmpty(*top_ref))
	{
		int temp = pop(top_ref);
		reverse(top_ref);
		insertAtBottom(top_ref, temp);
	}
}

bool check(int y, int x)
{
	return (x >= 0 && x <= 9 && y >= 0 && y <= 9);
}

Stack *solve(int labyrinth[10][10])
{
	Stack *ans = (Stack *)malloc(sizeof(Stack));
	ans->data = 32;
	ans->next = NULL;

	int x = 0;
	int y = 0;
	int i = 0;
	while (x != 9 || y != 9)
	{
		if (labyrinth[y][x + 1] == 1 && peek(ans) != 87 && x < 9) // east
		{														  // 69 ->
			printf("%d - x = %d || y = %d\n", i++, x, y);
			// printf("right ");
			x++;
			push(&ans, 69);
		}
		else if (labyrinth[y + 1][x] == 1 && peek(ans) != 78 && y < 9) // south
		{															   // 83 v
			printf("%d - x = %d || y = %d\n", i++, x, y);
			// printf("down ");

			y++;
			push(&ans, 83);
		}
		else if (labyrinth[y][x - 1] == 1 && peek(ans) != 69 && x > 1) // west
		{															   // 87 <-

			printf("%d - x = %d || y = %d\n", i++, x, y);
			// printf("left ");
			x--;
			push(&ans, 87);
		}
		else if (labyrinth[y - 1][x] == 1 && peek(ans) != 83 && y > 1) // north
		{															   // 78 ^

			printf("%d - x = %d || y = %d\n", i++, x, y);
			// printf("up ");
			y--;
			push(&ans, 78);
		}
		else
		{
			labyrinth[y][x] = 0;
			printf("else ");
			printf("%d - x = %d || y = %d\n", i++, x, y);

			int a = pop(&ans);
			switch (a)
			{
			case 69:
				x--;
				break;
			case 83:
				y--;
				break;
			case 87:
				x++;
				break;
			case 78:
				y++;
				break;
			}
		}
	}
	pop(&ans);
	return ans;
}

int main()
{
	// E -> | S v | W <- | N ^
	int labyrinth[10][10] = {
		{1, 1, 0, 1, 1, 1, 0, 1, 1, 0},
		{1, 1, 0, 1, 0, 0, 0, 0, 1, 0},
		{0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
		{0, 1, 0, 0, 1, 0, 1, 1, 0, 1},
		{1, 1, 1, 0, 1, 0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1, 0, 1, 0, 0, 1},
		{1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 0, 0, 1, 0, 1, 0, 0},
		{1, 0, 1, 1, 1, 1, 0, 1, 1, 0},
		{1, 0, 1, 1, 1, 0, 0, 1, 1, 1}};

	Stack *ans = solve(labyrinth);
	// reverse(&ans);
	Stack *b = ans;
	reverse(&b);
	display(b);

	return 0;
}
