#include <iostream>
#include <stdlib.h>

using namespace std;

class Person
{
private:
	string name;
	string surname;
	int sId;

public:
	Person()
	{
		this->name = "NAME";
		this->surname = "SURNAME";
		this->sId = -1;
	}
	Person(Person &obj)
	{
		this->name = obj.getName();
		this->surname = obj.getSurname();
		this->sId = obj.getID();
	}
	Person(string name, string surname, int sId)
	{
		this->name = name;
		this->surname = surname;
		this->sId = sId;
	}

	string getName()
	{
		return (this->name);
	}
	string getSurname()
	{
		return (this->surname);
	}
	int getID()
	{
		return (this->sId);
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setSurname(string surname)
	{
		this->surname = surname;
	}
	void setID(int id)
	{
		this->sId = id;
	}

	void printInfo()
	{
		cout << "name = " << this->name << endl;
		cout << "surname = " << this->surname << endl;
		cout << "Id = " << this->sId << endl;
	}

	// Operator Overloading

	friend ostream &operator<<(ostream &os, const Person &person);
};

ostream &operator<<(ostream &os, const Person &person)
{
	os << "Name: " << person.name << "\nSurname: " << person.surname << "\nID: " << person.sId << endl;
	return os;
}

class Count
{
private:
	int value;

public:
	Count() : value(0)
	{
	}

	void operator++()
	{
		value += 2;
	}

	void display()
	{
		cout << "Count: " << value << endl;
	}
};

int main()
{
	system("CLEAR");
	// Person ayberk("Ayberk", "Saygı", 15);
	// Person Arda = *new Person("a", "y", 1);
	// Arda.printInfo();
	// cout << endl;

	// cout << ayberk << endl;

	Count count1;
	++count1;
	count1.display();

	return 1;
}