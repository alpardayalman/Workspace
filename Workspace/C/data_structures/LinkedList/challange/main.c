#include "header.h"

int main()
{
	nodes_c *head = NULL;
	int userInput;
	print_menu();
	scanf("%d", &userInput);
	while (userInput != 0)
	{
		int pos;
		int value;
		switch (userInput)
		{
		case 1:
			printf("Siranin basina koymak icin bir sayi girin: ");
			scanf("\n%d", &value);
			insert_node_start(&head, value);
			break;
		case 2:
			printf("Siranin sonuna koymak icin bir sayi girin: ");
			scanf("\n%d", &value);
			insert_node_last(&head, value);
			break;
		case 3:
			printf("Pozisyona gore koymak icin lutfen bir sayi girin: ");
			scanf("\n%d", &value);
			printf("Pozisyon: ");
			scanf("\n%d", &pos);
			insert_node_pos(head, value, pos);
			break;
		case 4:
			printf("Pozisyona gore sil: ");
			scanf("\n%d", &pos);
			delete (&head, pos);
			break;
		case 5:
			printf("Pozisyona gore sil: ");
			scanf("\n%d", &pos);
			del_nod_pos(&head, pos);
			break;
		case 6:
			printf("Bir sayi girin: ");
			scanf("\n%d", &value);
			printf("degistirmek istediginiz pozisyon: ");
			scanf("\n%d", &pos);
			update_nod_value_pos(head, value, pos);
			break;
		case 7:
			printf("Index bulmak icin bir sayi girin: ");
			scanf("\n%d", &value);
			printf("%d\n", search_elem(head, value));
			break;
		case 8:
			printf("Sortlaniyor.\n");
			sortNode(&head);
			break;
		case 9:
			print_nodes(&head);
			break;
		case 0:
			printf("Bye");
			return 1;
		case 10:
			print_menu();
			break;
		default:
			printf("Lutfen 0-10 arasi bir sayi girin.\n");
			break;
		}
		printf("\n-- ");
		scanf("%d", &userInput);
	}
}