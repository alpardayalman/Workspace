#include "Person/Person.h"

int main()
{
	Student arda(102);
	Instructor Ayberk(19);
	Ayberk.setClass(GEOGRAPHY);
	Ayberk.setGrade(arda,GEOGRAPHY,70);
	Ayberk.setGrade(arda,MATH,0);
	arda.getGrades();


	return 1;
}