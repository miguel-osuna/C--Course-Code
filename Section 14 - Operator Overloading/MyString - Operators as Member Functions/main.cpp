#include <iostream>
#include "mystring.h"
using namespace std;

int main()
{
	MyString myFirstName("Miguel"); // Overloaded Constructor Called
	MyString myLastName("Osuna"); // Overloaded Constructor Called
	MyString fullName;

	myFirstName = -myFirstName;
	myLastName = -myLastName;

	fullName = myFirstName + " angel " + myLastName + " angulo";

	fullName.display();

	return 0;
}

