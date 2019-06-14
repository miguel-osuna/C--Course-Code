/*
	Purpose: Demonstrating Static Binding - Destructor. 
	This should throw a Warning because of the non-virtual Destructors
	Author: Miguel Osuna
	Date: 5/29/2019
*/

#include <iostream>
#include <vector>
using namespace std;

class Account
{
public:
	virtual void display()
	{
		cout << "In Account::withdraw" << endl;
	}
	~Account()
	{
		cout << "Account::destructor" << endl;
	}
};

class Check: public Account
{
public:
	virtual void display()
	{
		cout << "In Check::withdraw" << endl;
	}
	~Check()
	{
		cout << "Check::destructor" << endl;
	}

};

class Savings: public Account
{
public:
	virtual void display()
	{
		cout << "In Savings::withdraw" << endl;
	}
	~Savings()
	{
		cout << "Savings::destructor" << endl;
	}
};

class Trust: public Account
{
public:
	virtual void display()
	{
		cout << "In Trust::withdraw" << endl;
	}
	~Trust()
	{
		cout << "Trust::destructor" << endl;
	}
};

int main()
{
	cout << "-------Pointers-------" << endl;
	Account *p1 = new Account();
	Account *p2 = new Check();
	Account *p3 = new Savings();
	Account *p4 = new Trust();

	Account *p_arr[] {p1, p2, p3, p4};
	for(auto p: p_arr)
		p->display();

	cout << "\n-------Clean up-------" << endl;
	delete p1;
	delete p2;
	delete p3;
	delete p4;

	return 0;
}