#include <iostream>

using namespace std;

class Room
{
	// Attributes
	// Access Specifier
	// Public
	// Protected
	// Private
public:
	double length;
	double width;
	double height;

	// Constructor

	// Methods

	double calculateArea()
	{
		return length * width;
	}

	double calculateVolume()
	{
		return length * width * height;
	}
};

int main()
{
	Room room1;

	room1.height = 5;
	room1.length = 10;
	room1.width = 15;

	cout << room1.calculateArea() << endl;
	cout << room1.calculateVolume() << endl;

	return 0;
}