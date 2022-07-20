#include <iostream>

using namespace std;

class Base
{
public:
	int pub = 3;

	int getPvt()
	{
		return pvt;
	}

protected:
	int prot = 2;

private:
	int pvt = 1;
};

class PublicDerived : public Base
{
public:
	int getProt()
	{
		return prot;
	}
};

class ProtectedDerived : protected Base
{
public:
	int getProt()
	{
		return prot;
	}

	int getPub()
	{
		return pub;
	}
};

class PrivateDerived : private Base
{
public:
	int getProt()
	{
		return prot;
	}
	int getPub()
	{
		return pub;
	}
};

int main()
{
	// PublicDerived object1;
	// cout<<"Private: " << object1.getPvt() << endl;
	// cout<<"Protected: " << object1.getProt() << endl;
	// cout << "Public: " << object1.pub << endl;

	// ProtectedDerived object;
	// cout << "Private: cannot be accessed." << endl;
	// cout << "Protected: " << object.getProt() << endl;
	// cout << "Public: " << object.getPub() << endl;

	PrivateDerived obj;
	cout << "Private cannot be accessed" << endl;
	cout << "Protected: " << obj.getProt() << endl;
	cout << "Public: " << obj.getPub() << endl;

	return 0;
}