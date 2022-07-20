#include <iostream>
#include "Time.h"
#include <iomanip>
using namespace std;

Time::Time(const int h, const int m, const int s) : hour(h), minute(m), second(s) {}

void Time::setTime(const int h, const int m, const int s){
	this->hour = h;
	this->minute = m;
	this->second = s;
}

void Time::printTime(void)
{
	cout << setw(2) << setfill('0') << hour << ":"
		 << setw(2) << setfill('0') << minute << ":"
		 << setw(2) << setfill('0') << second << endl;
}

bool Time::equals(const Time &obj)
{
	return (obj.hour == this->hour && obj.minute == this->minute && obj.second == this->second);
}