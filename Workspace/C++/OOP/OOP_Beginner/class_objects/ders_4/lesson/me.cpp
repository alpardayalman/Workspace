#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
	Time hulio(10, 20, 30), arda(20, 11, 34);
	hulio.printTime();
	arda.printTime();
	if (arda.equals(hulio))
		cout << "objects are equal" << endl;
	else
		cout << "XX" << endl;

	return (0);
}