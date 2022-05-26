/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardayalman <ardayalman@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:46:48 by ardayalman        #+#    #+#             */
/*   Updated: 2022/05/26 18:45:25 by ardayalman       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Node
{
	int key;
	struct Node *next;
};

struct Graph
{
	int numVertices;
	struct Node **adjList;
	int *visited;
};

struct Graph *node_init(int vertex)
{
	struct Graph *graph = malloc(sizeof(struct Graph));
	graph->numVertices = vertex;

	graph->adjList = (struct Node **)malloc(sizeof(struct Node *) * vertex);
	graph->visited = malloc(vertex * sizeof(int));
	for (int i = 0; i < vertex; i++)
	{
		graph->adjList[i] = NULL;
	}
	return (graph);
}

struct Node *create_node(int vertex)
{
	struct Node *ret = malloc(sizeof(struct Node));
	ret->key = vertex;
	ret->next = NULL;
	return (ret);
}

void add(struct Graph *graph, int src, int dest)
{
	struct Node *key = create_node(src);
	key->next = graph->adjList[dest];
	graph->adjList[dest] = key;

	key = create_node(dest);
	key->next = graph->adjList[src];
	graph->adjList[src] = key;
}

void printGraph(struct Graph *graph)
{
	int v;
	for (v = 0; v < graph->numVertices; v++)
	{
		struct Node *temp = graph->adjList[v];
		printf("\nVertex %d: ", v);
		while (temp)
		{
			printf("%d -> ", temp->key);
			temp = temp->next;
		}
		printf("\n");
	}
}

void myDFS(struct Graph *graph, int vertex)
{
	struct Node *temp = graph->adjList[vertex];
	graph->visited[vertex] = 1;
	printf("Visited: %d\n", vertex);
	while (temp)
	{
		int connectedVertex = temp->key;
		if (graph->visited[connectedVertex] == 0)
		{
			DFS(graph, connectedVertex);
		}
		temp = temp->next;
	}
}

int main()
{
	struct Graph *graph = node_init(6);
	add(graph, 0, 1);
	add(graph, 0, 2);
	add(graph, 0, 3);
	add(graph, 2, 4);
	add(graph, 4, 5);

	printGraph(graph);

	DFS(graph, 0);

	return 0;
}