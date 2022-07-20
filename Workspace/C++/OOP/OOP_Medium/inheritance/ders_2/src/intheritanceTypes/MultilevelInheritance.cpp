#include <iostream>
#include <stdlib.h>
#include <unordered_map>
using namespace std;

class A
{
public:
	void display()
	{
		cout << "Base Class" << endl;
	}
};

class B : public A
{
};
class C : public B
{
};

class Mammal
{
public:
	Mammal()
	{
		cout << "Mammal!" << endl;
	}
	void x()
	{
	}
};

class Winged
{
public:
	void x()
	{
	}
	Winged()
	{
		cout << "Winged!" << endl;
	}
};

class Bat : public Mammal, public Winged
{

};


class Animal
{
public:
	void info()
	{
		cout << "Im an animal!" << endl;
	}
};

class Dog : public Animal
{
public:
	void bark()
	{
		cout << "Im a dog!" << endl;
	}
};

class Cat : public Animal
{
public:
	void meow()
	{
		cout << "Im a cat!" << endl;
	}
};

int
main()
{
	system("CLEAR");
	// C obj;
	// obj.display();

	// Bat b1;
	// b1.Winged::x();

	Dog dog;
	cout<<"Dog class: "<<endl;
	dog.info();
	dog.bark();

	Cat cat;
	cout<<"\nCat Class: "<<endl;
	cat.info();
	cat.meow();




	return 0;
}