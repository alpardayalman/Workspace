/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardayalman <ardayalman@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:46:48 by ardayalman        #+#    #+#             */
/*   Updated: 2022/05/25 10:07:44 by ardayalman       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Node
{
	int a;
	struct Node *next;
};

struct Graph
{
	int numVertices;
	struct Node **adjList;
};

struct Graph *node_init(int vertex)
{
	struct Graph *graph = malloc(sizeof(struct Graph));
	graph->numVertices = vertex;

	graph->adjList = (struct Node **)malloc(sizeof(struct Node *) * vertex);
	for (int i = 0; i < vertex; i++)
	{
		graph->adjList[i] = NULL;
	}
	return (graph);
}

struct Node *create_node(int vertex)
{
	struct Node *ret = malloc(sizeof(struct Node));
	ret->a = vertex;
	ret->next = NULL;
	return (ret);
}

void add(struct Graph *graph, int src, int dest)
{
	struct Node *a = create_node(src);
	a->next = graph->adjList[dest];
	graph->adjList[dest] = a;

	a = create_node(dest);
	a->next = graph->adjList[src];
	graph->adjList[src] = a;
}

void printGraph(struct Graph *graph)
{
	int v;
	for (v = 0; v < graph->numVertices; v++)
	{
		struct Node *temp = graph->adjList[v];
		printf("\n Vertex %d: ", v);
		while (temp)
		{
			printf("%d -> ", temp->a);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main()
{
	struct Graph *graph = node_init(4);
	add(graph, 0, 1);
	add(graph, 0, 2);
	add(graph, 0, 3);
	add(graph, 1, 2);

	printGraph(graph);

	return 0;
}