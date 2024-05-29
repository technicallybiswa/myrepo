#include <iostream>
using namespace std;
void show(int *,int *);//prototype
int main()
{
	int x=10,y=20;
	cout<<"Before function call x is  "<<x<<" y is "<<y<<"\n";
	show(&x,&y);//call by value
	cout<<"After function call x is  "<<x<<" y is "<<y<<"\n";
}

void show(int *x,int *y)
{

	*x=*x+5;
	*y=*y+5;
	cout<<"in the function x is  "<<*x<<" y is "<<*y<<"\n";
}

