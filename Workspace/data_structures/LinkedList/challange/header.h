#ifndef _STRUCT
#define _STRUCT

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodes_u
{
	int	value;
	struct nodes_u *next;
} nodes_c;


nodes_c	*create_node(int sayi);
int	insert_node_start(nodes_c	**node, int sayi);
int	insert_node_last(nodes_c	**node, int sayi);
int	insert_node_pos(nodes_c	*node, int sayi, int pos);
int	del_nod_pos(nodes_c	**node, int pos);
int	update_nod_value_pos(nodes_c	*node, int sayi, int pos);
int	search_elem(nodes_c	*node, int sayi);
int	print_nodes(nodes_c	**node);
void	print_menu(void);
void	delete(nodes_c	**node, int value);
void	swap(nodes_c *a, nodes_c *b);
void	sortNode(nodes_c	**node);
#endif