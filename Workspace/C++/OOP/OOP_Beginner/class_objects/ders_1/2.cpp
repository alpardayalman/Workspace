#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	system("CLEAR"); // !!!!

	// int *pointVar;

	// pointVar = new int;

	// *pointVar = 45;

	// ? pointerVar = new dataType;

	int *pointVar;

	pointVar = new int;
	*pointVar = 45;
	cout << *pointVar << endl;

	delete pointVar;

	cout << *pointVar << endl;

	return 0;
}
