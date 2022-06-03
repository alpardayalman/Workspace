#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main()
{
	int fd = open("text.txt", O_RDONLY);
	int rest = open("result.c", O_RDWR);
	char *buff = calloc('\0', 250);
	read(fd, buff, 250);
	printf("%s", buff);
	write(rest, buff, strlen(buff));
	close(fd);
	close(rest);
}