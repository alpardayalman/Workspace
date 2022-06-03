#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	int fd = open("book.txt", O_RDONLY);
	int rest = open("bitch.du", O_RDWR);

	char *string = malloc(250);
	read(fd, string, 250);
	printf("%s", string);
	write(rest, string, strlen(string));
	close(fd);
	close(rest);
}