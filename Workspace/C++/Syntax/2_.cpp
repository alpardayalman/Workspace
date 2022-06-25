#include <iostream>

using namespace std;
#define PI 3.14
int main()
{
	int r;

	cin>>r;
	float a = PI * r *r;
	float b = (1/3)*PI*r*r;

	cout<<((a < b)? "koney":"dayre")<<endl;
	return 0;
}