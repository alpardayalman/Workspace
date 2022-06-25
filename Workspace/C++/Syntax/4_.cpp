#include <iostream>

using namespace std;
void cumt(int i)
{
	if (i % 5 == 0 && (i % 7))
		cout<<i<<endl;
}

int main()
{
	for (int i = 0; i <= 1000;i++,cumt(i));
	return 0;
}