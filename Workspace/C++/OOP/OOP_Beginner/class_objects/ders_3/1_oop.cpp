#include <iostream>
using namespace std;

class Student{
	public:
		string name;
		void printInfo(){
			cout<<"Name: " <<this->name<<endl;
		}

		Student(string name){
			this->name = name;
		}
};

int main(){
	Student ayberk = *new Student("Ayberk");
	ayberk.printInfo();
}