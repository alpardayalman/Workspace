#include "so_long.h"

static test	*createstruct(char **map);

static int solveMazeUtil(test *main, int x, int y, char sol[main->height][main->width]);

static int isSafe(test *main, int x, int y)
{
	if (x >= 0 && x < main->height && y >= 0 && y < main->width && (main->maze[x][y] != '1'))
	{
		printf("%d %d\n",main->width, main->height);
		return 1;
	}
	return 0;
}

static int *findP(test *main)
{
	for (int h = 0; h < main->height; h++)
	{
		for (int w = 0; w < main->width; w++)
		{
			if (main->maze[h][w] == 'P')
			{
				int *a = malloc(sizeof(int)*2);
				a[0] = h;
				a[1] = w;
				return (a);
			}
		}
	}
	return NULL;
}

int solveMaze(char **map)
{
	test *main = createstruct(map);
	char sol[main->height][main->width];
	for (int i = 0; i < main->height; i++)
	{
		for (int j = 0; j < main->width; j++)
			sol[i][j] = '1';
		sol[i][main->width] = '\0';
	}
	if (solveMazeUtil(main, findP(main)[0], findP(main)[1], sol) == 0)
		return 0;
	return 1;
}

static int solveMazeUtil(test *main, int x, int y, char sol[main->height][main->width])
{
	static int a = 0;
	a++;
	if (main->maze[x][y] == 'E') {
		sol[x][y] = '0';
		return 1;
	}
	if (isSafe(main, x, y) == 1) {
		if (sol[x][y] == '0' || a > 6000)
			return 0;
		sol[x][y] = '0';
		if (solveMazeUtil(main, x, y + 1, sol) == 1)
			return 1;
		if (solveMazeUtil(main, x + 1, y, sol) == 1)
			return 1;
		if (solveMazeUtil(main, x, y - 1, sol) == 1)
			return 1;
		if (solveMazeUtil(main, x - 1, y, sol) == 1)
			return 1;
		sol[x][y] = '1';
		return 0;
	}
	return 0;
}

static int getlenh(char **map)
{
	int i = 0;
	for (; map[i]; i++);
	return (i);
}

static int getlenw(char **map)
{
	int i = 0;
	for (; map[0][i]; i++);
	return (i);
}

static test	*createstruct(char **map)
{
	test *main = malloc(sizeof(test));
	main->height = getlenh(map);
	main->width = getlenw(map);
	main->maze = map;
	return (main);
}
