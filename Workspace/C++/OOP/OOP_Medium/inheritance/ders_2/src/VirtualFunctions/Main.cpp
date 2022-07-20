#include <iostream>
using namespace std;

class Base
{
public:
	virtual void print()
	{
		cout << "Base" << endl;
	}
};

class Derived : public Base
{
public:
	void print()
	{
		cout << "Derived" << endl;
	}
};

class Animal
{
private:
	string type;

public:
	Animal() : type("Animal") {}

	virtual string getType()
	{
		return type;
	}
};

class Dog : public Animal
{
private:
	string type;

public:
	Dog() : type("Dog") {}

	string getType() override
	{
		return type;
	}
};

class Cat : public Animal
{
private:
	string type;

public:
	Cat() : type("Cat") {}

	string getType() override
	{
		return type;
	}
};

void print(Animal *animal)
{
	cout << "Animal: " << animal->getType() << endl;
}

int main()
{
	// Derived derived;
	// Base *base = &derived;

	// base->print();

	// Animal* animal = new Animal();
	// Animal* dog = new Dog();
	// Animal* cat = new Cat();

	// print(animal);
	// print(dog);
	// print(cat);

	return 0;
}