/*
	Purpose: Stack Unwinding. func_a() exception will come first than func_c() exception
	Author: Miguel Osuna
	Date: 6/6/2019
*/

#include <iostream>
using namespace std;

void func_c()
{
	cout << "Starting func_c" << endl;
	throw 0;
	cout << "Finishing func_c" << endl;
}

void func_b()
{	
	cout << "Starting func_b" << endl;
	func_c();
	cout << "Finishing func_b" << endl;
}

void func_a()
{
	cout << "Starting func_a" << endl;
	throw 0;
	func_b();
	cout << "Finishing func_a" << endl;
}

int main()
{
	cout << "Starting main" << endl;
	try
	{
		func_a();
	}

	catch(int &exc)
	{
		cout << "Caught error in main" << endl;
	}

	return 0;
}