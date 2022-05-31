#include "graph.h"

Node createNode(int v)
{
	Node newNode = (Node)malloc(sizeof(adjList_t));
	if (!newNode)
		err_malloc();

	newNode->vertex = v;
	newNode->next = NULL;

	return newNode;
}

Graph createGraph(int n, graph_type type)
{
	Graph graph = (Graph)malloc(sizeof(graph_t));
	if (!graph)
		err_malloc();
	graph->numVertices = n;
	graph->type = type;

	graph->adjListArr = (adjList_p)malloc(n * sizeof(adjList_t));
	if (!graph->adjListArr)
		err_malloc();

	for (int i = 0; i < n; i++)
	{
		graph->adjListArr[i].head = NULL;
		graph->adjListArr[i].numMembers = 0;
	}

	return graph;
}

void destroyGraph(Graph graph)
{
	if (graph)
	{
		if (graph->adjListArr)
		{
			for (int i = 0; i < graph->numVertices; i++)
			{
				Node adjListPtr = graph->adjListArr[i].head;
				while (adjListPtr)
				{
					Node temp = adjListPtr;
					adjListPtr = adjListPtr->next;
					free(temp);
				}
			}
			free(graph->adjListArr);
		}
		free(graph);
	}
}

void addEdge(graph_t *graph, int src, int dest)
{
	Node newNode = createNode(dest);
	newNode->next = graph->adjListArr[src].head;
	graph->adjListArr[src].head = newNode;
	graph->adjListArr[src].numMembers++;

	if (graph->type == UNDIRECTED)
	{
		newNode = createNode(src);
		newNode->next = graph->adjListArr[dest].head;
		graph->adjListArr[dest].head = newNode;
		graph->adjListArr[dest].numMembers++;
	}
}

void displayGraph(Graph graph)
{
	for (int i = 0; i < graph->numVertices; i++)
	{
		Node adjListPtr = graph->adjListArr[i].head;
		printf("\n%d: ", i);
		while (adjListPtr)
		{
			printf("%d->", adjListPtr->vertex);
			adjListPtr = adjListPtr->next;
		}
		printf("NULL\n");
	}
}

int main()
{
	Graph uGraph = createGraph(5, UNDIRECTED);
	Graph dGraph = createGraph(5, DIRECTED);

	addEdge(uGraph, 0, 1);
	addEdge(uGraph, 0, 4);
	addEdge(uGraph, 1, 2);
	addEdge(uGraph, 1, 3);
	addEdge(uGraph, 1, 4);
	addEdge(uGraph, 2, 3);
	addEdge(uGraph, 3, 4);

	addEdge(dGraph, 0, 1);
	addEdge(dGraph, 0, 4);
	addEdge(dGraph, 1, 2);
	addEdge(dGraph, 1, 3);
	addEdge(dGraph, 1, 4);
	addEdge(dGraph, 2, 3);
	addEdge(dGraph, 3, 4);

	printf("\nUNDIRECTED GRAPH");
	displayGraph(uGraph);
	destroyGraph(uGraph);

	printf("\nDIRECTED GRAPH");
	displayGraph(dGraph);
	destroyGraph(dGraph);
}