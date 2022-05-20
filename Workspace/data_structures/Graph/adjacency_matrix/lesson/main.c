#include <stdio.h>
#include <stdlib.h>

#define V 4

void init(int **a){
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V;j++) {
			a[i][j] = 0;
		}
	}
}

void addEdge(int **a, int src, int dest) {
	a[src][dest] = 1;
	a[dest][src] = 1;
}

void printMat(int **a) {
	for (int i = 0; i < V; i++) {
		printf("%d: ",i);
		for (int j = 0; j < V;j++) {
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int **adjMatrix;
	adjMatrix = (int **)malloc(sizeof(int **));
	for (int i = 0; i < V; i++) {
		adjMatrix[i] = (int *)malloc(sizeof(int *)*V);
	}

	init(adjMatrix);

	addEdge(adjMatrix,0,1);
	addEdge(adjMatrix,0,2);
	addEdge(adjMatrix,0,3);
	addEdge(adjMatrix,1,2);

	printMat(adjMatrix);

	return 0;
}

//adj list yap
// BOOL a-->b?1:0;