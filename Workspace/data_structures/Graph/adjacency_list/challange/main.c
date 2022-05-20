#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

struct node
{
	int vertex;
	struct node *next;
};

struct Graph
{
	int numVertices;
	struct node **adjLists;
};

struct node *creatEdge(int value) {
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->vertex = value;
	new->next = NULL;
	return (new);
}

struct Graph *createGraph(int num) {
	struct Graph *new = (struct Graph *)malloc(sizeof(struct Graph));
	new->numVertices = num;
	new->adjLists = (struct node **)malloc(sizeof(struct node*)*num);
	for (int i = 0; i < num; i++) {
		new->adjLists[i] = NULL;
	}
	return (new);
}

void addadj(struct Graph *node, int a, int b) {
	struct node *new = creatEdge(a);
	new->next = node->adjLists[b];
	node->adjLists[b] = new;

	new = creatEdge(b);
	new->next = node->adjLists[a];
	node->adjLists[a] = new;
}

void printrec(struct node *hey) {
	if (hey == NULL)
		return;
	printf("-> %d",hey->vertex);
	printrec(hey->next);
}

void printgrapy(struct Graph *node) {
	for (int i = 0; i < node->numVertices;i++) {
		printf("%d: ",i);
		printrec(node->adjLists[i]);
		printf("\n");
	}
}
//a-->b?1:0
bool check(struct Graph *node, int a, int b) {
	struct node *A = node->adjLists[a];
	while (A) {
		if (A->vertex == b)
			return true;
		A = A->next;
	}
	return false;
}

int main() {
	struct Graph *head = createGraph(4);
	addadj(head,0,1);
	addadj(head,0,2);
	addadj(head,0,3);
	addadj(head,1,2);
	printgrapy(head);
	printf("\n");
	if (check(head,3,1))
		printf("var");
	else
		printf("yok");
	return 1;
}