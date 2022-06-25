#include <iostream>
#include <stdlib.h>
using namespace std;

struct student
{
	string name;
	string surname;
	int grade;
};

int main()
{
	struct student **students;
	students = (struct student **)malloc(sizeof(struct student *) * 3);
	for (int i = 0; i < 3; i++)
	{
		students[i] = (struct student *)malloc(sizeof(struct student));
		cout << "Name: ";
		cin >> students[i]->name;

		cout << "Surname: ";
		cin >> students[i]->surname;

		cout << "Grade: ";
		cin >> students[i]->grade;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << "Name: " << students[i]->name << endl;
		cout << "Surname: " << students[i]->surname << endl;
		cout << "Grade: " << students[i]->grade << endl;
	}

	return (0);
}