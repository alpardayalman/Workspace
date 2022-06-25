#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum
{
	UNDIRECTED = 0,
	DIRECTED
} graph_type;

typedef struct adjListNode
{
	int vertex;
	struct adjListNode *next;
} adjListNode, *Node;

typedef struct adjList
{
	int numMembers;
	adjListNode *head;
} adjList_t, *adjList_p;

typedef struct Graph
{
	int numVertices;
	graph_type type;
	adjList_p adjListArr;
} graph_t, *Graph;

void err_exit(char *msg)
{
	printf("[Error]: %s\nExiting...\n", msg);
	exit(1);
}

void err_malloc(void)
{
	err_exit("Unable to allocate memory!");
}

#endif
