#include<iostream>
using namespace std;

class person
{
public:
	string name;
};

int main()
{
	person p1;
	p1.name = "уехЩ";
	cout << "Hello World!"<<endl;
	cout << p1.name;
}