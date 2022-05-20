#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};

// Calculate Height
int height(struct Node *node)
{
	if (node == NULL)
		return 0;
	return node->height;
}

int maxNum(int a, int b)
{
	return (a > b) ? a : b;
}

struct Node *newNode(int key)
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

// RightRotate
struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *beta = x->right;
	x->right = y;
	y->left = beta;
	y->height = maxNum(height(y->left), height(y->right)) + 1;
	x->height = maxNum(height(x->left), height(x->right)) + 1;

	return x;
}

struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *beta = y->left;
	y->left = x;
	x->right = beta;

	y->height = maxNum(height(y->left), height(y->right)) + 1;
	x->height = maxNum(height(x->left), height(x->right)) + 1;

	return y;
}

// Get balance factor
int getBalance(struct Node *node)
{
	if (node == NULL)
		return 0;
	return height(node->left) - height(node->right);
}

struct Node *insert(struct Node *node, int key)
{
	if (node == NULL)
		return (newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;

	// Update balance factor for each node!

	node->height = 1 + maxNum(height(node->left), height(node->right));
	int balance = getBalance(node);

	// If balanceFactor > 1,
	// it means the height of the left subtree
	// is greater than that of the right subtree.
	// So, do a right rotation or left-right rotation
	if (balance > 1)
	{
		if (key < node->left->key) // If newNodeKey < leftChildKey do right rotation.
			return rightRotate(node);
		else
		{ // Else, do left-right rotation.
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
	}
	// If balanceFactor < -1,
	// it means the height of the right subtree
	// is greater than that of the left subtree.
	// So, do right rotation or right-left rotation
	else if (balance < -1)
	{
		if (key > node->right->key) // newNodeKey > rightChildKey -> left rotation.
			return leftRotate(node);
		else
		{ // Else, do right-left rotation
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
	}
	return node;
}

struct Node *minValue(struct Node *node)
{
	struct Node *current = node;

	while (current->left)
	{
		current = current->left;
	}

	return current;
}

struct Node *deleteNode(struct Node *root, int key)
{
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else
	{
		if ((root->right == NULL) || (root->left == NULL))
		{
			struct Node *temp = root->left ? root->left : root->right;

			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
			{
				*root = *temp;
			}
			free(temp);
		}
		else
		{
			struct Node *temp = minValue(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}

	if (root == NULL)
		return root;

	// Update Balance Factor!

	root->height = 1 + maxNum(height(root->left), height(root->right));
	int balance = getBalance(root);
	if (balance > 1)
	{
		if (getBalance(root->left) >= 0)
			return rightRotate(root);
		else
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}

	else if (balance < -1)
	{
		if (getBalance(root->right) <= 0)
		{
			return leftRotate(root);
		}
		else
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}

	return root;
}

void inorder(struct Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

int main()
{
	struct Node *root = NULL;
	int c[] = {33, 13, 53, 9, 21, 61, 8, 11};
	for (int i = 0; i < sizeof(c) / sizeof(c[0]); i++)
	{
		root = insert(root, c[i]);
	}

	inorder(root);

	root = deleteNode(root, 13);
	printf("After Deletion!\n");
	inorder(root);

	return 0;
}