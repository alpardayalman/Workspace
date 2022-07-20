#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <iomanip>
using namespace std;

class Person
{
	private:
		int age;
		int height;
		int weight;
		int id;
		string name;
		string surname;
	public:
		//constructor
		Person(const int a = 12, const int h = 170, const int w = 70, const int id = 0, const string name = "NAME", const string surname = "SURNAME");
		~Person();
		//showers
		int	showAge(void);
		int	showHeight(void);
		int	showWeight(void);
		int	showID(void);
		string	showName(void);
		string	showSurname(void);
		//changers
		void changeAge(int a);
		void changeHeight(int h);
		void changeWeight(int w);
		void changeId(int id);
		void changeName(string name);
		void changeSurname(string surname);
		//calculations
		double	vki();
		double feet();
		double lbs();
		//compare
		bool equals(const Person &);
		friend ostream &operator<<(ostream &os, const Person &person);
};
#endif