#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <iomanip>
using namespace std;

enum classes
{
	MATH = 0,
	GEOGRAPHY,
	HISTORY,
	ENGLISH,
	PHILOSOPHY,
	ART,
	SPORT
};

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
		int	getAge(void);
		int	getHeight(void);
		int	getWeight(void);
		int	getID(void);
		string	getName(void);
		string	getSurname(void);
		//changers
		void setAge(int a);
		void setHeight(int h);
		void setWeight(int w);
		void setId(int id);
		void setName(string name);
		void setSurname(string surname);
		//calculations
		double	vki();
		double feet();
		double lbs();
		//compare
		bool equals(const Person &);
		friend ostream &operator<<(ostream &os, const Person &person);
};

class Student : public Person
{
	private:
		int	sid;
		int	grades[7];
	public:
		Student(const int sId = 0);
		~Student();
		void	setsID(int id);
		int		getsID(void);
		void	setGrades(int course, int grade);
		void	getGrades(void);
};

class Instructor : public Person
{
	private:
		int	Iid;
		int	classes_thought[7];
	public:
		Instructor(int id = 0);
		~Instructor();
		void	setStudent(Student &);
		void	setGrade(Student &, int course, int grade);
		void	setClass(int course);
		bool	getClass(int course);
};
#endif