#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 50

struct MinHNode
{
	char item;
	unsigned freq;
	struct MinHNode *left, *right;
};

struct MinHeap
{
	unsigned size;
	unsigned capacity;
	struct MinHNode **array;
};

struct MinHNode *newNode(char item, unsigned freq)
{
	struct MinHNode *ret = (struct MinHNode *)malloc(sizeof(struct MinHNode));
	ret->freq = freq;
	ret->item = item;
	ret->left = ret->right = NULL;
	return (ret);
}

struct MinHeap *newHeap(unsigned capacity)
{
	struct MinHeap *ret = (struct MinHeap *)malloc(sizeof(struct MinHeap));
	ret->size = 0;
	ret->capacity = capacity;
	ret->array = (struct MinHNode **)malloc(sizeof(struct MinHNode *) * capacity);
	return (ret);
}

void swapMinHNode(struct MinHNode **a, struct MinHNode **b)
{
	struct MinHNode *ret = *b;
	*b = *a;
	*a = ret;
}

void minHeapify(struct MinHeap *minHeap, int idx)
{
}

int checkSizeOne(struct MinHeap *minHeap)
{
	return minHeap->size == 1;
}

struct MinHNode *extractMin(struct MinHeap *minHeap)
{
	struct MinHNode *ret = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->size - 1];
	--minHeap->size;
	minHeapify(minHeap, 0);
	return (ret);
}

void insertMinHeap(struct MinHeap *minHeap, struct MinHNode *minHeapNode)
{
	++minHeap->size;
	int i = minHeap->size - 1;

	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)
	{
		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap *minHeap)
{
	int n = minHeap->size - 1;

	for (int i = (n - 1) / 2; i >= 0; --i)
	{
		minHeapify(minHeap, i);
	}
}

int isLeaf(struct MinHNode *root)
{
	return !(root->left) && !(root->right);
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}

struct MinHeap *createAndBuildMinHeap(char item[], int freq[], int size)
{
	struct MinHeap *minHeap = newHeap(size);
	for (int i = 0; i < size; i++)
	{
		minHeap->array[i] = newNode(item[i], freq[i]);
	}

	minHeap->size = size;
	buildMinHeap(minHeap);

	return minHeap;
}

struct MinHNode *buildHuffmanTree(char item[], int freq[], int size)
{
	struct MinHNode *left, *right, *top;
	struct MinHeap *minHeap = createAndBuildMinHeap(item, freq, size);

	while (!checkSizeOne(minHeap))
	{
		left = extractMin(minHeap);
		right = extractMin(minHeap);

		top = newNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		insertMinHeap(minHeap, top);
	}
	return extractMin(minHeap);
}

void printHuffmanCodes(struct MinHNode *root, int arr[], int top)
{
	if (root->left)
	{
		arr[top] = 0;
		printHuffmanCodes(root->left, arr, top + 1);
	}
	if (root->right)
	{
		arr[top] = 1;
		printHuffmanCodes(root->right, arr, top + 1);
	}
	if (isLeaf(root))
	{
		printf("  %c   | ", root->item);
		printArray(arr, top);
	}
}

void HuffmanCodes(char item[], int freq[], int size)
{
	struct MinHNode *root = buildHuffmanTree(item, freq, size);
	int arr[MAX_TREE_HT], top = 0;
	printHuffmanCodes(root, arr, top);
}

int main()
{
	char arr[] = {'A', 'B', 'C', 'D'};
	char freq[] = {5, 1, 6, 3};

	int size = sizeof(arr) / sizeof(arr[0]);

	printf(" Char | Huffman code ");
	printf("\n--------------------\n");

	HuffmanCodes(arr, freq, size);
}
