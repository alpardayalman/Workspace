#include "Person.h"


int main()
{
	Person hulio(10,170,80,106,"Oha","Gunduz"), arda(22,170,50,242,"Arda","Yalman");
	if (!hulio.equals(arda))
	{
		cout << arda.feet() << '\n' << arda.lbs() << "\n" << arda << '\n' << arda.vki() << endl;
	}

	return (0);
}