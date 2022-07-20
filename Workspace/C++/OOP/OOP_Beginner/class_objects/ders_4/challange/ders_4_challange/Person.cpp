#include "Person.h"

// Time::Time(const int h, const int m, const int s) : hour(h), minute(m), second(s) {}

Person::Person(const int a, const int h, const int w, const int id, const string n, const string s) : age(a), height(h),weight(w),id(id),name(n),surname(s){}

Person::~Person(){
	cout<<"Destructor Called!"<<endl;
}

int Person::showAge(){
	return (this->age);
}

int Person::showHeight(){
	return (this->height);
}

int Person::showWeight(){
	return (this->weight);
}

int Person::showID(){
	return (this->id);
}

string Person::showName(){
	return (this->name);
}

string Person::showSurname(){
	return (this->surname);
}

void Person::changeAge(int a)
{
	this->age = a;
}

void Person::changeHeight(int h)
{
	this->age = h;
}

void Person::changeWeight(int w)
{
	this->weight = w;
}

void Person::changeId(int id)
{
	this->id = id;
}

void Person::changeName(string name)
{
	this->name = name;
}

void Person::changeSurname(string surname)
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