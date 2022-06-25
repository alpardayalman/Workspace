#include <iostream>

using namespace std;

int main()
{
	string a;
	for (int i = 0; i < 3; i++)
	{
		cout<<"Sifre gir (evet): ";
		cin>>a;
		if (a.compare("arda"))
			continue;
		else
			break;
	}
}