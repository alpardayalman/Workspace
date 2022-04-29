#include "header.h"

nodes_c	*create_node(int sayi) {
	nodes_c	*new = (nodes_c *) malloc(sizeof(nodes_c));
	new->next = NULL;
	new->value = sayi;
	return (new);
}

/*1 = New node created.
*2 = New node is added to front.
*-1 = Memory error.
*/
int	insert_node_start(nodes_c	**node, int sayi) {
	nodes_c	*new = NULL;
	new = create_node(sayi);
	if (!new)
		return -1;
	if (!node){
		fprintf(stderr,"insert_node_start\n");
		*node = new;
		return 1;
	}
	else {
		new->next = *node;
		*node = new;
		return 2;
	}
}

/*-1 = Memory error.
*1 = New node created to the front.
*2 = New node added to the end.
*/
int	insert_node_last(nodes_c	**node, int sayi) {
	nodes_c	*new = create_node(sayi);
	nodes_c	*decoy = *node;
	if (!new)
		return -1;
	if (!decoy){
		*node = new;
		return 1;
	}
	else {
		while (decoy->next) {
			decoy = decoy->next;
		}
		decoy->next = new;
		return 2;
	}
}

/*-1 = Memory error.
*1 = New node created to the front.
*2 = New node is added to it's place.
*/
int	insert_node_pos(nodes_c	*node, int sayi, int pos) {
	nodes_c	*new = create_node(sayi);
	nodes_c	*decoy = node;
	nodes_c	*prev = NULL;
	int	i = 0;
	if (!new)
		return -1;
	if (!node){
		node = new;
		return 1;
	}
	else {
		while (decoy && i <= pos){
			prev = decoy;
			decoy = decoy->next;
			i++;
		}
		new->next = decoy;
		prev->next = new;
		return 2;
	}
}

/*-1 = No node to delete.
*1 = end returned.
*/
int	del_nod_pos(nodes_c	**node, int pos) {
	nodes_c	*decoy = *node;
	nodes_c	*prev = NULL;
	size_t	i = 0;
	if (!decoy)
		return -1;
	if (pos <= 0) {
		prev = decoy;
		*node = decoy->next;
		free(prev);
		return 97;
	}
	while (decoy->next && i <= pos){
		prev = decoy;
		decoy = decoy->next;
		i++;
	}
	prev->next = decoy->next;
	if (decoy)
		free(decoy);
	return 1;
}

/*-1 = No node.
*1 = end returned.
*/
int	update_nod_value_pos(nodes_c	*node, int sayi, int pos) {
	nodes_c	*decoy = node;
	size_t	i = 0;
	if (!node)
		return -1;
	while (decoy && i < pos) {
		decoy = decoy->next;
		i++;
	}
	if (decoy)
		decoy->value = sayi;
	return 1;
}

/*-1 = No node.
*1 = end returned.
*index = if found.
*0 = if the element is not found.
*/
int	search_elem(nodes_c	*node, int sayi) {
	nodes_c	*decoy = node;
	size_t	i = 0;
	if (!node)
		return -1;
	while (decoy)
	{
		if (sayi == decoy->value)
			return i;
		decoy = decoy->next;
		i++;
	}
	return 0;
}

/*-1 = No node.
*1 = all displayed.
*/
int	print_nodes(nodes_c	**node) {
	nodes_c	*decoy = *node;
	if (!node)
		return -1;
	while (decoy)
	{
		printf("|%d|--> ",decoy->value);
		decoy = decoy->next;
	}
	printf("(NULL)\n");
	return 1;
}

void delete(nodes_c	**node, int value) {
    if (node == NULL) {
		printf("Liste Bos");
		return ;
	}
    nodes_c *ptr = *node;
    while(ptr->next) {
        if (ptr->next->value == value) {
            ptr->next = ptr->next->next;
            return ;
        }
        ptr = ptr->next;
    }
}

void    swap(nodes_c *a, nodes_c *b) {
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}

void sortNode(nodes_c	**node){
	nodes_c *ptr;
    nodes_c *ptrl = NULL;
    bool swape;

    do
    {
        ptr = *node;
        swape = false;
        while (ptr->next != ptrl) {
            if (ptr->value > ptr->next->value) {
                swape = true;
                swap(ptr, ptr->next);
            }
            ptr = ptr->next;
        }
        ptrl = ptr;
    }
    while(swape);
}


void	print_menu(void) {
	printf("Secim yap bakalim:\n"
	"1 - Siranin basina koy.\n"
	"2 - Siranin sonuna koy.\n"
	"3 - pozisyona gore koy.\n"
	"4 - degere gore sil.\n"
	"5 - pozisyona gore sil.\n"
	"6 - pozisyona gore sayi degistir.\n"
	"7 - Index bul\n"
	"8 - Listeyi sortla\n"
	"9 - listeyi goster.\n"
	"0 - Cikis yap.\n"
	"10 - Menu.\n"
	);
	printf(":: ");
}