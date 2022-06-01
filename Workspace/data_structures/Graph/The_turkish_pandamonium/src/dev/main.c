#include "the_turkish_pandamonium.h"
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
			city->adjDistances[i] = atoi(ret[i + 2]);
		cities[index] = *city;
	}
	printf("\n");
}
