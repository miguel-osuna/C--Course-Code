/*
	Purpose: Demonstrating Class Interfaces. 
	Author: Miguel Osuna
	Date: 5/29/2019
*/

#include <iostream>
#include <vector>
using namespace std;

class I_Printable 
{
	// To respect the insertion operator syntaxis, we use a global friend operator
	// Any class Derived from I_Printable will be printable
	friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
	// This pure virtual method will force the subclasses to implement the same method
	// to keep being 'Concrete'. Different 'print' methods will be called depending on the 
	// Derived Class
	virtual void print(std::ostream &os) const = 0; // Pure virtual function
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
	obj.print(os);
	return os;
}

// Concrete Class
class Account: public I_Printable
{
public:
	virtual void display()
	{
		cout << "In Account::withdraw" << endl;
	}
	virtual ~Account()
	{
		cout << "Account::destructor" << endl;
	}
	virtual void print(std::ostream &os) const override
	{
		os << "Account Display";
	}
};

// Concrete Class
// Account 'is a' I_Printable
// and Check 'is a' Account
class Check: public Account
{
public:
	// Adding override will force the compiler to throw an error
	// if the method is not the same as the Base class one
	virtual void display()
	{
		cout << "In Check::withdraw" << endl;
	}
	virtual ~Check()
	{
		cout << "Check::destructor" << endl;
	}
	virtual void print(std::ostream &os) const override
	{
		os << "Check Display";
	}

};

// Concrete Class
// Account 'is a' I_Printable
// and Savings 'is a' Account
class Savings: public Account
{
public:
	// Adding override will force the compiler to throw an error
	// if the method is not the same as the Base class one
	virtual void display()
	{
		cout << "In Savings::withdraw" << endl;
	}
	virtual ~Savings()
	{
		cout << "Savings::destructor" << endl;
	}
	virtual void print(std::ostream &os) const override
	{
		os << "Savings Display";
	}
};

// Concrete Class
// Account 'is a' I_Printable
// and Trust 'is a' Account
class Trust: public Account
{
public:
	// Adding override will force the compiler to throw an error
	// if the method is not the same as the Base class one
	virtual void display()
	{
		cout << "In Trust::withdraw" << endl;
	}
	virtual ~Trust()
	{
		cout << "Trust::destructor" << endl;
	}
		virtual void print(std::ostream &os) const override
	{
		os << "Trust Display";
	}
};

int main()
{
	Account *p1 = new Account();
	cout << *p1 << endl;

	// This will dynamic bind the 'print' method for the class Check
	Account *p2 = new Check();
	cout << *p2 << endl;

	// This will dynamic bind the 'print' method for the class Savings
	Account *p3 = new Savings();
	cout << *p3 << endl;

	// This will dynamic bind the 'print' method for the class Trust
	Account *p4 = new Trust();
	cout << *p4 << endl;

	return 0;
}