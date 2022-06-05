#include "the_turkish_pandamonium.h"
City *createCity(char **dist, char **adj)
{
	City *ret = malloc(sizeof(City));
	printf("%s %s\n", dist[0], dist[1]);
	ret->cityName = ft_strdup(dist[1]);
	int city_code = ft_atoi(dist[0]);
	int all_adj = sizeOfArray(adj);
	ret->adjacencies = (Adjacent **)malloc(sizeof(Adjacent *) * all_adj);
	for (int i = 0; i < all_adj - 1; i++)
	{
		ret->adjacencies[i] = (Adjacent *)malloc(sizeof(Adjacent));
		ret->adjacencies[i]->cityName = strdup(adj[i + 1]);
		ret->adjacencies[i]->code = 0;
		ret->adjacencies[i]->distance = 0;
	}
	if (city_code == 0)
		ret->code = 1;
	else
		ret->code = city_code;
	for (int i = 0; dist[i + 2]; i++)
		ret->Distances[i] = atoi(dist[i + 2]);
	return (ret);
}

int sizeOfArray(char **array)
{
	int ret = 0;
	for (; array[ret]; ret++)
		;
	return (ret);
}
