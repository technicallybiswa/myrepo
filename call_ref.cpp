#include <iostream>
using namespace std;
void show(int& ,int& );//prototype
int main()
{
	int x=10,y=20;
	cout<<"Before function call x is  "<<x<<" y is "<<y<<"\n";
	show(x,y);//call by value
	cout<<"After function call x is  "<<x<<" y is "<<y<<"\n";
}

void show(int& a,int& b) //received as reference (alias)
{

	a=a+5;
	b=b+5;
	cout<<"in the function x is  "<<a<<" y is "<<b<<"\n";
}

