#include "the_turkish_pandamonium.h"

int sizeOfArray(char **array)
{
	int ret = 0;
	for (; array[ret]; ret++)
		;
	return (ret - 1);
}
int main()
{
	int fd = open("./src/args/Distances.csv", O_RDONLY);
	City cities[81];

	for (int index = 0; index < 81; index++)
	{
		char **ret = ft_split(get_next_line(fd), ';');
		City *city = createCity(ret[0], ret[1]);
		printf("%s %d\n", city->cityName, city->code);
		for (int i = 0; ret[i + 2]; i++)
			city->Distances[i] = atoi(ret[i + 2]);
		cities[index] = *city;
	}
	fd = open("./src/args/Adjacencies.txt", O_RDONLY);
	for (int index = 0; index < 81; index++)
	{
		char **ret = ft_split(get_next_line(fd), ',');
		cities[index].adjacencies = createAdjList(sizeOfArray(ret));
		for (int index2 = 1; ret[index2]; index2++)
		{
			Adjacent *adj = malloc(sizeof(Adjacent));
			adj->cityName = strdup(ret[index2]);
			for (int i = 0; i < 81; i++)
			{
				if (strcmp(cities[i].cityName, adj->cityName) == 0)
				{
					adj->code = cities[i].code;
					adj->distance = cities[i].Distances[adj->code - 1];
					break;
				}
			}
			cities[index].adjacencies[index2] = *adj;
		}
	}

	printf("%s", cities[0].cityName);
}
