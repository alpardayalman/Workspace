#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (a == 0 || b == 0)
		return (-1);
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	return (a);
}

int max(int a, int b)
{
	return (a < b? b:a);
}
int min(int a, int b)
{
	return (a > b? b:a);
}

int lcm(int a, int b)
{
	for(int i = max(a,b); ;i++){
		if((i % a == 0) && (i % b == 0)){
			return i;
		}
	}
}

int main()
{
	cout<<lcm(4,6);
	return 0;
}