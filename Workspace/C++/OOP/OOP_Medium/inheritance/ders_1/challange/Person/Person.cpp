#include "Person.h"

// Time::Time(const int h, const int m, const int s) : hour(h), minute(m), second(s) {}

//Person.
Person::Person(const int a, const int h, const int w, const int id, const string n, const string s) : age(a), height(h),weight(w),id(id),name(n),surname(s){}

Person::~Person(){
	cout<<"Person Destructor Called!"<<endl;
}

int Person::getAge(){
	return (this->age);
}

int Person::getHeight(){
	return (this->height);
}

int Person::getWeight(){
	return (this->weight);
}

int Person::getID(){
	return (this->id);
}

string Person::getName(){
	return (this->name);
}

string Person::getSurname(){
	return (this->surname);
}

void Person::setAge(int a)
{
	this->age = a;
}

void Person::setHeight(int h)
{
	this->age = h;
}

void Person::setWeight(int w)
{
	this->weight = w;
}

void Person::setId(int id)
{
	this->id = id;
}

void Person::setName(string name)
{
	this->name = name;
}

void Person::setSurname(string surname)
{
	this->surname = surname;
}
//  Vücut Ağırlığı (kg.) / Boy uzunluğunun karesi (m2.)
double Person::vki()
{
	double	ret = (double)this->weight/((this->height/100) * (this->height/100));
	return (ret);
}

double Person::feet()
{
	double	ret = (double)(this->height/100) * 3.28084;
	return (ret);
}

double Person::lbs()
{
	double	ret = (double)(this->weight * 2.20462);
	return (ret);
}

ostream &operator<<(ostream &os, const Person &person)
{
	os << "Name: " << person.name << "\nSurname: " << person.surname << "\nID: " << person.id << "\nAge: " << person.age << "\nHeight " << person.height << "\nWeight: " << person.weight << endl;
	return os;
}

bool Person::equals(const Person &obj)
{
	return (this->age == obj.age && this->height == obj.height && this->weight == obj.weight && this->id == obj.id && !(this->name.compare(obj.name)) && !(this->surname.compare(obj.surname)));
}

//student

Student::Student(const int sID)
{
	this->sid = sID;
	for (int i = 0; i < 7; i++)
		this->grades[i] = 0;
}

Student::~Student(){}

void Student::setsID(int id)
{
	this->sid = id;
}

void Student::setGrades(int course, int grade)
{
	if (course > 7 || course < 0)
		return ;
	if (grade < 0)
		grade = 0;
	else if (grade > 100)
		grade = 100;
	this->grades[course] = grade;
}

int Student::getsID(void)
{
	return (this->sid);
}

void Student::getGrades(void)
{
	cout << "\nThe name of the student: " << this->getName() << "\nThe surname of the student: " << this->getSurname() << "\nStudent ID: " << this->getsID()
	<< "\nMath: " << this->grades[MATH] << "\nGeography: "<< this->grades[GEOGRAPHY] <<"\nHistory: "<< this->grades[HISTORY] <<"\nEnglish: "<< this->grades[ENGLISH]
	<< "\nPhilosophy: "<< this->grades[PHILOSOPHY] << "\nArt: "<< this->grades[ART] << "\nSport: " << this->grades[SPORT] << endl;
}

// Instructor

Instructor::Instructor(int id)
{
	this->Iid = id;
	for (int i = 0; i < 7;i++)
		this->classes_thought[i] = 0;
}

Instructor::~Instructor(){}

void	Instructor::setGrade(Student &obj, int course, int grade)
{
	if (this->classes_thought[course] == 0)
	{
		cout << "The teacher do not teach this class" << endl;
		return ;
	}
	obj.setGrades(course, grade);
}

void	Instructor::setClass(int course)
{
	if (course > 7 || course < 0)
		return ;
	this->classes_thought[course] = 1;
}

bool	Instructor::getClass(int course)
{
	if (course > 7 || course < 0)
		return false;
	return (this->classes_thought[course]);
}