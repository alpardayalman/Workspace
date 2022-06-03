#include "the_turkish_pandamonium.h"
City *createCity(char *code, char *name)
{
	City *ret = malloc(sizeof(City));
	ret->cityName = ft_strtrim(name, " ");
	int city_code = ft_atoi(code);
	ret->adjacencies = NULL;
	if (city_code == 0)
		ret->code = 1;
	else
		ret->code = city_code;
	return (ret);
}

Adjacent *createAdjList(int size)
{
	Adjacent *ret = malloc(size * sizeof(Adjacent));
	return (ret);
}
