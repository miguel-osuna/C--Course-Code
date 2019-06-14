/*
	Purpose: Demonstrating Dynamic Binding - Class Base References. 
	Author: Miguel Osuna
	Date: 5/29/2019
*/

#include <iostream>

// This class uses dynamic polymorphism for the withdraw method
// We'll learn about virtual functions in the next video
class Account 
{
public:
    virtual void display() 
    {
        std::cout << "In Account::display" << std::endl;
    }
    virtual ~Account() {  }
};

class Checking: public Account  
{
public:
    // Adding override will force the compiler to throw an error
    // if the method is not the same as the Base class one
    virtual void display() 
    {
        std::cout << "In Checking::display" << std::endl;
    }
    virtual ~Checking() {  }
};

class Savings: public Account  
{
public:
    // Adding override will force the compiler to throw an error
    // if the method is not the same as the Base class one
    virtual void display() 
    {
        std::cout << "In Savings::display" << std::endl;
    }
    virtual ~Savings() {  }
};

class Trust: public Account  
{
public:
    // Adding override will force the compiler to throw an error
    // if the method is not the same as the Base class one
    virtual void display() 
    {
        std::cout << "In Trust::display" << std::endl;
    }
    virtual ~Trust() {  }
};

//There just needs to be a BASE CLASS REFERENCE, no 'virtual' keyword
void do_display(Account &account) 
{
    std::cout << "Outside of Class" << std::endl;
    // In this case, 'display' is already a virtual function
    account.display();
    std::cout << std::endl;
}

int main() {

    Account a;
    Account &ref = a;
    ref.display();		    // In Account::display

    Trust t;
    Account &ref1 = t;
	ref1.display();        // In Trust::display
	std::cout << std::endl;

	Account a1;
	Savings a2;
	Checking a3;
	Trust a4;
   
	do_display(a1);       // In Account::display
	do_display(a2);       // In Savings::display
	do_display(a3);       // In Checking::display
	do_display(a4);       // In Trust::display

	return 0;
}