#ifndef _HEAD
#define _HEAD

#define BUFFER_SIZE 4
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct Node
{
	char *cityName;
	int code;
	int adjDistances[81];
} City;

char *ft_substr(char const *s, unsigned int start, size_t len);
size_t ft_count_word(char const *s, char c);
char *ft_strcreate(const char *s, char c, size_t i);
char **ft_split(char const *s, char c);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strjoin(char *s1, char *s2);
char *ft_get_line(char *remainder);
char *ft_new_left_str(char *remainder);
char *ft_read_to_left_str(int fd, char *remainder);
char *get_next_line(int fd);
#endif