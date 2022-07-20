#include <iostream>
using namespace std;

class Distance
{
private:
	int meter;
	friend int addFive(Distance);

public:
	Distance() : meter(5) {}
};

int addFive(Distance obj)
{
	obj.meter += 5;
	return obj.meter;
}

class B;
class A
{
private:
	int num;
	friend int add(A, B);

public:
	A() : num(10) {}
};

class B
{
private:
	int num;
	friend int add(A, B);

public:
	B() : num(20) {}
};

int add (A a, B b)
{
	return (a.num + b.num);
}

int main()
{
	// Distance obj;
	// cout << "Distance: " << addFive(obj) << endl;
	// obj.meter += 5;
	A a; B b;
	cout<<"sum = "<<add(a,b)<<endl;
	return 0;
}