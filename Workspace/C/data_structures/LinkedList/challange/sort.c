#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
struct t_nod {
	int data;
	struct t_nod *next;
};

struct t_nod *create(int a) {
	struct t_nod *ret = malloc(sizeof(struct t_nod));
	ret->data = a;
	ret->next = NULL;
	return (ret);
}


bool check(struct t_nod **a) {
	struct t_nod *new = *a;
	for (;new->next;new=new->next) {
		if(new->data > new->next->data)
			return false;
	}
	return true;
}

int cmp(int a, int b) {
	return (a <= b);
}
//en bastan baslasin eger giderken oldugu degerden daha kucuk birtane bulursa basa atsin.
struct t_nod *addhead(struct t_nod **b, struct t_nod *a) {
	a->next = *b;
	*b = a;
	return (*b);
}

struct t_nod *sort_list(struct t_nod *lst, int (*cmp)(int,int)) {
	struct t_nod *ptr = lst;
	struct t_nod *prev = NULL;
	while (!check(&lst)) {
		while (ptr->next != NULL) {
			if (!cmp(ptr->data,ptr->next->data)) {
				prev = ptr->next;
				ptr->next = ptr->next->next;
				lst = addhead(&lst, prev);
				break;
			}
			ptr=ptr->next;
		}
		ptr = lst;
	}
	return (lst);
}

void display(struct t_nod **a) {
	struct t_nod *b = *a;
	while (b) {
		printf("--> %d ",b->data);
		b = b->next;
	}
	printf("\n");
}

int main() {
	struct t_nod *a = create(11);
	struct t_nod *ret = a;
	int c[] = {32,10,43,34,67,100,1,23,41,34,52,75};
	for (int i = 0; i < sizeof(c)/sizeof(c[0]);i++,ret=ret->next) {
		ret->next = create(c[i]);
	}
	display(&a);
	a = sort_list(a,cmp);
	display(&a);
}