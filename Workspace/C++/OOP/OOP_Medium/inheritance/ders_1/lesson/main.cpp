#include <iostream>

using namespace std;

class Animal
{
public:
	void eat()
	{
		cout << "I can eat!" << endl;
	}

	void sleep()
	{
		cout << "I can sleep!" << endl;
	}
};

class Dog : public Animal
{
public:
	void bark()
	{
		cout << "I can bark!" << endl;
	}
};

int main()
{
	Dog dog1;
	dog1.eat();

	return 0;
}

/*
	
	Implement a Person class that has name, surname, sid....
	Implement a Student class that inherits Person class that has takenCourses list 
	Implement a Instructor class that inherits person class
	Implement a Course class that has flds..
*/