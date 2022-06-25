#include <iostream>

using namespace std;

int main(){

	// //printf
	// cout<<"Hello World!"<<endl;

	// //scanf
	// int age;
	// cout<<"Enter your age: ";
	// cin>>age;
	// cout<<"Your age is: "<<(char)age<<endl;

	// for (int i = 0; i < 10; cout<<i<<endl, i++);

	string str1;
	cout<<"Enter a string: ";
	getline(cin,str1);
	cout<<str1<<endl;

	cout<<str1.length()<<endl;
	return 0;
}