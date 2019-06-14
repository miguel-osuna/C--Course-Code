/*
	Purpose: Multiple Exception Handling
	Author: Miguel Osuna
	Date: 6/6/2019
*/

#include <iostream>
using namespace std;

// Division By '0' Exception
class DivideByZeroException {

};

// Negative Values Exception
class NegativeValueException {
};

double average(int sum, int total);

int main()
{
	double avr {};
	try
	{
		avr = average(-100, 0);
		cout << avr << endl;
	}

	catch(const DivideByZeroException &exc)
	{
		cerr << "Sorry, can't divide by 0" << endl;
	}

	catch(const NegativeValueException &exc)
	{
		cerr << "Negative value error" << endl;
	}

	return 0;
}

double average(int sum, int total)
{
	if(total == 0)
		throw DivideByZeroException{};

	if(sum < 0 || total < 0)
		throw NegativeValueException{};

	return static_cast<double> (sum) / total;
}