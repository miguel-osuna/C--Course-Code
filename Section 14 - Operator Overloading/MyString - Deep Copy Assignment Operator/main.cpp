#include <iostream>
#include "mystring.h"
using namespace std;

int main()
{
	MyString someString;
	MyString myFirstName("Miguel");
	MyString myLastName("Osuna");
	MyString someName {"Angel"};

	myFirstName.display();
	myLastName.display();

	myFirstName = someName;
	myLastName = "Angulo";

	myFirstName.display();
	myLastName.display();
	return 0;
}