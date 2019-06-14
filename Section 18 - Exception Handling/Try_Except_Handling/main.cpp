/*
	Purpose: Testing Exception Handling
	Author: Miguel Osuna
	Date: 6/6/2019
*/

#include <iostream>
using namespace std;

int main()
{	
	int miles {};
	int gallons {};
	double milesPerGallons {};

	cout << "Enter the miles driven: ";
	cin >> miles;
	cout << "Enter the gallons used: ";
	cin >> gallons;

	try
	{
		if(gallons == 0)
			throw 0;
		milesPerGallons = static_cast<double>(miles) / gallons;
		cout << "Result: " << milesPerGallons << endl;
	}

	catch(int &exc)
	{
		cout << "Sorry, you can't divide by 0" << endl;
	}

	return 0;
}