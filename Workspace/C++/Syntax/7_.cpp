#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	string *a;
	a = (string *)malloc(sizeof(string) * 11);
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
			a[i] = "Arda";
		else
			a[i] = "Ayberk";
	}
	cout<<"bir ad ver: ";
	cin>>a[10];
	for (int i = 0; i < 10; i++)
	{
		if (a[i].compare(a[10]) == 0)
		{
			cout<<"true";
			return 0;
		}
	}
	return 1;
}