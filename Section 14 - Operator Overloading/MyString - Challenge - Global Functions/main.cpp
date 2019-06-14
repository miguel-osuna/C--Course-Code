#include <iostream>
#include "mystring.h"
using namespace std;

int main()
{
	MyString firstName{"Miguel"};
	MyString lastName{"Osuna"};
	firstName.display();

	-firstName;
	firstName.display();

	++firstName;
	firstName.display();

	cout << (firstName == lastName) << endl;
	cout << (firstName != lastName) << endl;
	cout << (firstName < lastName) << endl;
	cout << (firstName > lastName) << endl;

	MyString fullName {"Mr. "};
	fullName += firstName + " " + lastName + " Angulo";
	fullName.display();

	MyString test{"qwerty12345"};
	test = ++test;
	MyString newTest;
	newTest = test * 3;
	newTest.display();
	return 0;
}