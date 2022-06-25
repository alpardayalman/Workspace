#include <iostream>

using namespace std;

int main()
{
	int a[4];
	for (int i = 0; i < 4; i++)
	{
		cout<<"bir sayi ver: ";
		cin>>a[i];
		cout<<endl;
	}
	cout<<a[0]*a[2]<<endl;
	cout<<a[1] + a[3]<<endl;
	return 0;
}