#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node
{
	struct Node *right;
	struct Node *left;
	int data;
};

struct Node *create(int data)
{
	struct Node *new = malloc(sizeof(struct Node));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

struct Node *minValue(struct Node *nod)
{
	struct Node *new = nod;
	for (; new->left; new = new->left)
		;
	return (new);
}

struct Node *insert(struct Node *nod, int data)
{
	if (nod == NULL)
		return (create(data));
	else if (nod->data > data)
		nod->left = insert(nod->left, data);
	else if (nod->data < data)
		nod->right = insert(nod->right, data);
	return nod;
}

struct Node *delete (struct Node *nod, int data)
{
	if (nod == NULL)
		return (nod);
	if (nod->data > data)
		delete (nod->left, data);
	else if (nod->data < data)
		delete (nod->right, data);
	else
	{
		if (nod->left == NULL)
		{
			struct Node *new = nod->right;
			free(nod);
			return (new);
		}
		else if (nod->right == NULL)
		{
			struct Node *new = nod->left;
			free(nod);
			return (new);
		}
		else
		{
			struct Node *new = minValue(nod->right);
			nod->data = new->data;
			nod->right = delete (nod->right, nod->data);
		}
	}
	return nod;
}

void preOrder(struct Node *nod)
{
	if (nod == NULL)
	{
		return;
	}
	printf("%d -> ", nod->data);
	preOrder(nod->left);
	preOrder(nod->right);
}
void postOrder(struct Node *nod)
{
	if (nod == NULL)
	{
		return;
	}
	postOrder(nod->left);
	postOrder(nod->right);
	printf("%d -> ", nod->data);
}
void inOrder(struct Node *nod)
{
	if (nod == NULL)
	{
		return;
	}
	inOrder(nod->left);
	printf("%d -> ", nod->data);
	inOrder(nod->right);
}
void print_menu(void)
{
	printf("\n"
		"1 - Ekleme yap.\n"
		"2 - Bir deger sil.\n"
		"3 - Post Order.\n"
		"4 - In Order.\n"
		"5 - Pre Order.\n"
		"6 - Menu.\n"
		"0 - Cikis yap.\n");
	printf(":: ");
}
// Find the k'th smallest and largest nodes in BST
int count = 0;
struct Node *kthSmallest(struct Node *root, int k)
{
	// base case
	if (root == NULL)
		return NULL;

	// search in left subtree
	struct Node *left = kthSmallest(root->left, k);

	// if k'th smallest is found in left subtree, return it
	if (left != NULL)
		return left;

	// if current element is k'th smallest, return it
	if (k == ++count)
		return root;

	// else search in right subtree
	return kthSmallest(root->right, k);
}
// Convert binary tree to BST maintaining its original structure.

int main() {
	int a[] = {8,3,1,6,7,10,14,4};
	struct Node *root = NULL;
	for (int i = 0; i < (sizeof(a)/sizeof(a[0])); i++) {
		root = insert(root,a[i]);
	}
	printf("%d",kthSmallest(root,4)->data);
	return 1;
}
























// int main()
// {
// 	struct Node *head = NULL;
// 	int userInput;
// 	print_menu();
// 	scanf("%d", &userInput);
// 	while (userInput != 0)
// 	{
// 		int pos;
// 		int value;
// 		switch (userInput)
// 		{
// 		case 1:
// 			printf("Eklemek istediginiz degeri girin: ");
// 			scanf("%d", &value);
// 			printf("\n Eklendim\n");
// 			head = insert(head, value);
// 			break;
// 		case 2:
// 			printf("Eklemek istediginiz degeri girin: ");
// 			scanf("%d", &value);
// 			printf("\n Silindi\n");
// 			head = delete (head, value);
// 			break;
// 		case 3:
// 			postOrder(head);
// 			printf("\n");
// 			break;
// 		case 4:
// 			inOrder(head);
// 			printf("\n");
// 			break;
// 		case 5:
// 			preOrder(head);
// 			printf("\n");
// 			break;
// 		case 6:
// 			print_menu();
// 			break;
// 		case 7:
// 			scanf("%d",&value);
// 			printf("\n%d\n", kthSmallest(head,value)->data);
// 			break;
// 		default:
// 			exit(1);
// 			break;
// 		}
// 		printf("_____________________");
// 		printf("\n##: ");
// 		scanf("%d", &userInput);
// 	}
// }

// Find the k'th smallest and largest nodes in BST

// Convert binary tree to BST maintaining its original structure.

// Remove nodes from BST that is not located in given range
