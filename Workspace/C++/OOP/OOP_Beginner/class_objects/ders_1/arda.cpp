#include <iostream>
#include <stdlib.h>

using namespace std;

class Students
{
private:
	string name;
	string surname;
	int id;

public:
	// Default Constructor
	Students()
	{
		this->name = "USERNAME";
		this->surname = "SURNAME";
		this->id = -1;
	}
	// Copy Constructor
	Students(Students &obj)
	{
		this->name = obj.getName();
		this->surname = obj.getSurname();
		this->id = obj.getID();
	}

	// Parameterized Constructor
	Students(string name, string surname, int id)
	{
		this->name = name;
		this->surname = surname;
		this->id = id;
	}

	void printInfo()
	{
		cout << "Name of student :" << name << endl;
		cout << "Surname of student: " << surname << endl;
		cout << "Id of student: " << id << endl;
	}

	// Accessor Methods
	// Getters-Setters

	string getName()
	{
		return this->name;
	}

	void setName(string name)
	{
		this->name = name;
	}

	string getSurname()
	{
		return this->surname;
	}

	void setSurname(string surname)
	{
		this->surname = surname;
	}

	int getID()
	{
		return this->id;
	}

	void setID(int id)
	{
		this->id = id;
	}

	friend ostream &operator<<(ostream &os, const Students &obj);
};

ostream &operator<<(ostream &os, const Students &obj)
{
	os << "name: " << obj.name << "\nsurname: " << obj.surname << "\nid: " << obj.id << endl;
	return (os);
}

int main()
{
	system("CLEAR"); // !!!!
	Students *Arda = new Students("Arda", "Yalman", 45);
	Students Ayberk = *new Students("Ayberk", "Saygi", 109);

	Students Mehmet = *new Students();
	// Students *Koray = Ayberk;
	// Koray->setName("XXX");

	// Ayberk.printInfo();
	// cout << endl;
	// Arda->printInfo();

	// cout<<Arda->getName()<<endl;

	cout<<Ayberk<<endl;

	cout << endl;
	return 0;
}