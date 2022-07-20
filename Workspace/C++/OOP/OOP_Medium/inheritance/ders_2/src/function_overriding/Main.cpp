#include <iostream>
#include <unordered_map>

using namespace std;

class Base
{
public:
	void print()
	{
		cout << "Base Class" << endl;
	}
};

class Derived : public Base
{
public:
	void print()
	{
		cout << "Derived Class" << endl;
		Base::print();
	}
};

int main()
{
	// Derived derived;
	// derived.print();
	// unordered_map<string,int> x;
	// x.insert("x",15);

	// derived.Base::print();




	return 0;
}