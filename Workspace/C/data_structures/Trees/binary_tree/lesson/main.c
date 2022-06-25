#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *right;
	struct Node *left;
};

void printNode(struct Node *root) {
	printf("%d ",root->data);
}

void postOrder(struct Node *root) {
	if(root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	printNode(root);
}

void preOrder(struct Node *root) {
	if(root == NULL) return;
	printNode(root);
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(struct Node *root) {
	if(root == NULL) return;
	inOrder(root->left);
	printNode(root);
	inOrder(root->right);
}

struct Node *createNode(int data) {
	struct Node *ret = (struct Node *)malloc(sizeof(struct Node));
	ret->data = data;
	ret->right = NULL;
	ret->left = NULL;
	return (ret);
}

struct Node *insertLeft(struct Node *root, int data) {
	root->left = createNode(data);
	return (root->left);
}

struct Node *insertRight(struct Node *root, int data) {
	root->right = createNode(data);
	return (root->right);
}


int main() {
	struct Node *root = createNode(12);//6 8 9 12 14 16 18
	insertLeft(root,8);
	insertLeft(root->left,6);
	insertRight(root->left,9);
	insertRight(root,16);
	insertLeft(root->right,14);
	insertRight(root->right,18);
	printf("\n");
	inOrder(root);
	printf("\n");
	printf("\n");
	preOrder(root);
	printf("\n");
	printf("\n");
	postOrder(root);
	printf("\n");
}