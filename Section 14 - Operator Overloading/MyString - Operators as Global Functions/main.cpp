#include <iostream>
#include "mystring.h"
#include <string>
#include <cstring>
using namespace std;

int main()
{
	MyString myFirstName("Miguel"); // Overloaded Constructor Called
	MyString myLastName("Osuna"); // Overloaded Constructor Called
	MyString fullName; // No-args Constructor Called

	myFirstName = -myFirstName;
	myLastName = -myLastName;
	fullName = myFirstName + " " + myLastName; // MyString Concatenation
	fullName.display();

	if (myFirstName > myLastName)
		cout << "First name is larger than the last name" << endl;

	else
		cout << "Last name is larger than the first name" << endl;

	return 0;
}