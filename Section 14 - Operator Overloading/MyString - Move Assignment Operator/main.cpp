#include <iostream>
#include "mystring.h"
using namespace std;

int main()
{
	MyString myFirstName("Miguel"); // Overloaded Constructor Called
	MyString myLastName("Osuna"); // Overloaded Constructor Called
	myFirstName = "Angel"; // Overloaded Constructor, then Move Assignment Operator Called

	myFirstName.display();
	myLastName.display();

	myLastName = myFirstName;  // Copy Assignment Operator Called

	myFirstName.display();
	myLastName.display();
	return 0;
}