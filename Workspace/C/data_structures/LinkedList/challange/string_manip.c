#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
//Credits github: Alpardayalman
//Our struct.
struct node
{
	char data;
	struct node *next;
};
//My library function for strdup (from <string.h>).
char *ft_strdup(const char *str)
{
	char *ptr;
	size_t index;

	ptr = (char *)malloc(sizeof(*str) * (strlen(str) + 1));
	if (!ptr)
		return (NULL);
	index = -1;
	while (str[++index])
		ptr[index] = str[index];
	ptr[index] = '\0';
	return (ptr);
}
//To free the list after we use it.
void freeList(struct node *head)
{
	struct node *tmp;

	while (head->data != '\0')
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	if (head->data == '\0')
		free(head);
}
//Utility function to create node.
struct node *createNode(char data)
{
	struct node *ret = malloc(sizeof(struct node));
	ret->next = NULL;
	ret->data = data;
	return (ret);
}
//To add the new node on the top of the structure.
struct node *addHead(struct node **head, char data)
{
	struct node *ret = createNode(data);
	ret->next = *head;
	*head = ret;
	return (*head);
}
//From backwards I push the chars in the sentence to my linked stack.
struct node *addString(char *sentence)
{
	struct node *ret;
	ret = addHead(&ret, '\0');
	for (int a = strlen(sentence); a >= 0; a--)
		ret = addHead(&ret, sentence[a]);
	return ret;
}
//to calculate the length of my node until i see the null terminator.
int nodeLen(struct node **head)
{
	struct node *ret = *head;
	int i = 0;
	for (i=0;ret->data != '\0';i++, ret = ret->next);
	return i;
}
//Transfers the char data from our stack to our result.
void Transfer(struct node **head, char *result)
{
	struct node *ret = *head;
	int i;
	for (i = 0; ret->data != '\0'; i++, ret = ret->next)
		result[i] = ret->data;
	result[i] = '\0';
}
//Returns the length from our head data to the head data
int returnSpace(struct node *head)
{
	struct node *new = head;
	int i;
	for (i = 0;new->data != 32 && new->data != '\0'; new = new->next,i++);
	return i;
}
//Main algorithm, it reverses the next word if the length of the word is more than 4 (in a recursive manner).
struct node *altReverse(struct node *head)
{
	struct node *current = head;
	struct node *next;
	struct node *prev;
	int count = 0;
	int k = returnSpace(current);
	if (k > 4)
	{
		prev = current;
		for (int i = 0; i <= k; i++, prev = prev->next);
		for (int count = 0; current && count < k; count++, current = next) {
			next = current->next;
			current->next = prev;
			prev = current;
		}
		if (head)
			head->next = current;
	}
	else
		prev = current;
	if (current->data != '\0')
		current->next = altReverse(current->next);

	return prev;
}
//Main function.
void spin_words(const char *sentence, char *result)
{
	char *a = ft_strdup(sentence);
	struct node *main = addString(a);
	main = altReverse(main);
	// code wars'ta yok.
	Transfer(&main, result);
	printf("%s\n", result);
	freeList(main);
	free(a);
}

int main()
{
	struct node *a;
	char result[10];
	spin_words("spam", result);
	write(1,&result,strlen(result));
	return 0;
}