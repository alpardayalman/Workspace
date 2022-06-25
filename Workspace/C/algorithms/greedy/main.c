#include <stdio.h>
#include <stdlib.h>
// 20 10 5 2 1.

int main()
{
	int money;
	int twenies = 0;
	int tens = 0;
	int fives = 0;
	int twos = 0;
	int ones = 0;
	scanf("%d", &money);
	while (money > 0)
	{
		if (money - 20 >= 0)
		{
			twenies++;
			money -= 20;
		}
		else if (money - 10 >= 0)
		{
			tens++;
			money -= 10;
		}
		else if (money - 5 >= 0)
		{
			fives++;
			money -= 5;
		}
		else if (money - 2 >= 0)
		{
			twos++;
			money -= 2;
		}
		else if (money - 1 >= 0)
		{
			ones++;
			money--;
		}
	}
	printf("20s = %d\n10s = %d\n5s = %d\n2s = %d\n1s = %d", twenies, tens, fives, twos, ones);
}