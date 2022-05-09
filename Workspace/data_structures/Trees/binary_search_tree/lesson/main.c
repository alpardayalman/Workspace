#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node
{
	struct Node *right;
	struct Node *left;
	int data;
};

struct Node *newNode(int data)
{
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));
	new->data = data;
	new->left = new->right = NULL;
	return (new);
}

void inOrder(struct Node *root)
{
	if (root == NULL)
	{
		return;
	}
	inOrder(root->left);
	printf("%d -> ", root->data);
	inOrder(root->right);
}

void preOrder(struct Node *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d -> ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(struct Node *root)
{
	if (root == NULL)
	{
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf("%d -> ", root->data);
}

struct Node *insert(struct Node *root, int data)
{
	if (root == NULL)
		return (newNode(data));
	if (root->data < data)
		root->right = insert(root->right, data);
	else
		root->left = insert(root->left, data);
	return root;
}

// 1-leaf node
// 2-one child
// 3-two child

struct Node *minValue(struct Node *root)
{
	struct Node *min;

	// find the leftmost node
	if (root != NULL)
	{
		min = root;
		return minValue(root->left);
	}
	else
		return (min);
}

/*
struct Node *minValue(struct Node *root){
	struct Node *current = root;
	while(current && current->left){
		current = current->left;
	}
	return current;
}
*/
struct Node *delete (struct Node *root, int data)
{
	if (root == NULL)
	{
		return (root);
	}

	// Find the node to be deleted!
	if (root->data < data)
	{
		root->right = delete (root->right, data);
	}
	else if (root->data > data)
	{
		root->left = delete (root->left, data);
	}
	else
	{
		// No child or one child
		if (root->left == NULL)
		{
			struct Node *temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			struct Node *temp = root->left;
			free(root);
			return (temp);
		}

		// Both childs
		struct Node *succ = minValue(root->right);
		root->data = succ->data;
		root->right = delete (root->right, succ->data);
	}
	return root;
}

int main(void)
{
	int a[] = {8,3,1,6,7,10,14,4};
	struct Node *root = NULL;
	for (int i = 0; i < (sizeof(a)/sizeof(a[0])); i++) {
		root = insert(root,a[i]);
	}

	printf("Inorder Traversal!\n");
	inOrder(root);

	printf("\nAfter Deleting 10\n");
	root = delete(root,10);

	inOrder(root);
	return 0;
}

//Find the k'th smallest and largest nodes in BST

//Convert binary tree to BST maintaining its orginal structure.

//Remove nodes from BST that is not located in given range

