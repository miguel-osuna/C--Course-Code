/*
	Purpose: Multiple Exception Handling
	Author: Miguel Osuna
	Date: 6/6/2019
*/

#include <iostream>
using namespace std;

double average(int sum, int total);

int main()
{
	double avr {};
	try
	{
		avr = average(-100, -10);
		cout << avr << endl;
	}

	catch(int &exc)
	{
		cout << "Sorry, can't divide by 0" << endl;
	}

	catch(string &exc)
	{
		cout << exc << endl;
	}

	return 0;
}

double average(int sum, int total)
{
	if(total == 0)
		throw 0;

	if(sum < 0 || total < 0)
		throw string{"Negative value error"};

	return static_cast<double> (sum) / total;
}