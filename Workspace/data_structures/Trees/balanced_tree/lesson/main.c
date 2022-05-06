#include <stdio.h>
#include <stdlib.h>
#include <math.h>
enum bool{false,true};

struct Node
{
	int data;
	struct Node *right;
	struct Node *left;
};

struct Node *createNode(int data) {
	struct Node *ret = (struct Node *)malloc(sizeof(struct Node));
	ret->data = data;
	ret->right = NULL;
	ret->left = NULL;
	return (ret);
}
///Odev
int checkBalance(struct Node *root, int *height) {
	//Check for emptiness

	int leftHeight = 0, rightHeight = 0;
	int l = 0, r = 0;

	if(root == NULL){
		*height = 0;
		return true;
	}

	l = checkBalance(root->left, &leftHeight);
	r = checkBalance(root->right, &rightHeight);

	*height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
	if(abs(leftHeight-rightHeight) >= 2)
		return false;
	else
		return (l && r);
}


int myCheckBalance(struct Node *root, int *height) {
	int l = 0, r = 0;
	int leftH = 0, rightH = 0;
	if (root == NULL) {
		*height = 0;
		return true;
	}

	l = checkBalance(root, &leftH);
	r = checkBalance(root, &rightH);

	*height = rightH > leftH?rightH:leftH + 1;

	if (abs(rightH - leftH) >= 2) {
		return false;
	}
	else
		return (l && r);
}

int main() {
	int height = 0;
	struct Node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);

	if (myCheckBalance(root,&height))
		printf("Balanced");
	else
		printf("!Balanced");
}