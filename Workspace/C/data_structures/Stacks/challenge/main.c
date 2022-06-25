#include "header.h"

int main() {
	Stack *head = NULL;
	int	userInput;
	print_menu();
	scanf("%d",&userInput);
	while (userInput != 0) {
		int	pos;
		int	value;
		switch (userInput)
		{
		case 1:
			printf("\nSiranin basina koy: ");
			scanf("\n%d",&value);
			push(&head, value);
			break;
		case 2:
			printf("Siranin basindan silindi\n");
			pop(&head);
			break;
		case 3:
			display(head);
			break;
		case 4:
			reverse(&head);
			break;
		case 5:
			sortStack(&head);
			break;
		case 6:
			print_menu();;
			return 1;
		default:
			printf("Lutfen 0-6 arasi bir sayi girin.\n");
			break;
		}
		printf("\n_______\n");
		printf("\n--> ");
		scanf("%d",&userInput);
	}
}