#include "Person/Person.h"

int main()
{
	Student arda(102);
	Instructor Ayberk(19);
	Instructor Memo(1);
	Memo.setClass(MATH);
	Memo.setGrade(arda,MATH,120);
	Memo.setGrade(arda,GEOGRAPHY,20);
	arda.getGrades();


	return 1;
}