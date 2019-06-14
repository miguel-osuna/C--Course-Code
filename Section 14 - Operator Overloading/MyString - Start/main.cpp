#include <iostream>
#include "mystring.h"
using namespace std;

int main()
{
	MyString someString;
	MyString myFirstName("Miguel");
	myFirstName.display();

	myFirstName = "Angel";
	myFirstName.display();

	return 0;
}