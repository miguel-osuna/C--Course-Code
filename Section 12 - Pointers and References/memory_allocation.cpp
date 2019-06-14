#include <iostream>

using namespace std;

int main()
{
	//Creating a new pointer by memory allocation
	int *ptr {nullptr};
	ptr = new int;
	*ptr = 100;

	//Printing contents before deallocating
	cout << ptr << endl;
	cout << *ptr << endl;

	delete ptr;

	//Printing contents after deallocating memory from pointer
	cout << ptr << endl;
	cout << *ptr << endl;

	ptr = nullptr;

	//Printing contents after asigning nullptr to original pointer
	cout << ptr << endl;
	cout << *ptr << endl;

	return 0;
}