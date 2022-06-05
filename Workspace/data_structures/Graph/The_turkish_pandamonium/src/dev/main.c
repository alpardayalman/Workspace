#include "the_turkish_pandamonium.h"

int main()
{
	int Dist_fd = open("./src/args/Distances.csv", O_RDONLY);
	int Adj_fd = open("./src/args/Adjacencies.txt", O_RDONLY);
	City cities[81];

	for (int index = 0; index < 81; index++)
	{
		char **dist_string_array = ft_split(get_next_line(Dist_fd), ';');
		char **adj_string_array = ft_split(get_next_line(Adj_fd), ',');
		City *city = createCity(dist_string_array, adj_string_array);
		cities[index] = *city;
	}
	printf("%p %p\n", cities->adjacencies[0]->cityName, cities->cityName);
	printf("%s %s\n", cities->adjacencies[0]->cityName, cities->cityName);
}
