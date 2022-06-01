#include "../../inc/the_turkish_pandamonium.h"

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char *ft_strchr(const char *s, int c)
{
	int s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	while (s_len >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		s_len--;
	}
	return (NULL);
}

char *ft_strjoin(char *s1, char *s2)
{
	unsigned int i;
	unsigned int j;
	char *s3;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i] != 0)
		s3[i] = s1[i];
	j = -1;
	while (s2[++j] != 0)
	{
		s3[i + j] = s2[j];
	}
	s3[i + j] = 0;
	free(s1);
	return (s3);
}

char *ft_get_line(char *remainder)
{
	int index;
	char *string;

	index = 0;
	if (!remainder[index])
		return (NULL);
	while (remainder[index] && remainder[index] != '\n')
		index++;
	string = (char *)malloc(sizeof(char) * (index + 2));
	if (!string)
		return (NULL);
	index = 0;
	while (remainder[index] && remainder[index] != '\n')
	{
		string[index] = remainder[index];
		index++;
	}
	if (remainder[index] == '\n')
	{
		string[index] = remainder[index];
		index++;
	}
	string[index] = '\0';
	return (string);
}

char *ft_new_left_str(char *remainder)
{
	int index;
	int index_2;
	char *string;

	index = 0;
	while (remainder[index] && remainder[index] != '\n')
		index++;
	if (!remainder[index])
	{
		free(remainder);
		return (NULL);
	}
	string = (char *)malloc(sizeof(char) * (ft_strlen(remainder) - index + 1));
	if (!string)
		return (NULL);
	index++;
	index_2 = 0;
	while (remainder[index])
		string[index_2++] = remainder[index++];
	string[index_2] = '\0';
	free(remainder);
	return (string);
}

char *ft_read_to_left_str(int fd, char *remainder)
{
	char *buff;
	int rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(remainder, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		remainder = ft_strjoin(remainder, buff);
	}
	free(buff);
	return (remainder);
}

char *get_next_line(int fd)
{
	char *string;
	static char *remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	remainder = ft_read_to_left_str(fd, remainder);
	if (!remainder)
		return (NULL);
	string = ft_get_line(remainder);
	remainder = ft_new_left_str(remainder);
	return (string);
}

// fd = file descriptor
// main function
int main()
{
	int fd = open("../args/Distances.csv", O_RDONLY);
	char *string;
	City cities[81];

	for (int index = 0; index < 81; index++)
	{
		char **ret = ft_split(get_next_line(fd), ';');
		City city;
		city.code = atoi(ret[0]);
		city.cityName = strdup(ret[1]);

		for (int i = 0; ret[i + 2]; i++)
		{
			city.adjDistances[i] = atoi(ret[i + 2]);
		}

		cities[index] = city;
	}

	printf("\n");
}