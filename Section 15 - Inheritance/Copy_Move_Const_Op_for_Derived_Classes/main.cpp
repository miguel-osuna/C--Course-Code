/*Purpose: Adding the Copy and Move Copy Constructors*/

#include <iostream>
using namespace std;

class Base
{
private:
	int value;

public:
	// Base No-args Constructor
	Base() : value{0} {cout << "Base No-args Constructor Called" << endl; }
	
	// Base int Constructor
	Base(int x): value{x} { cout << "int Base Constructor Called" << endl; }
	
	// Base Copy Constructor
	Base(const Base &other)
	: value{other.value} 
	{
		cout << "Base Copy Constructor Called" << endl;
	}
	
	// Base Assignment Operator. It returns a Base reference
	Base &operator=(const Base &rhs)
	{
		cout << "Base Assignment Operator" << endl;
		if(this != &rhs)
		{	
			value = rhs.value;
		}
		return *this;
	}

	// Base Destructor
	~Base() { cout << "Base Destructor Called" << endl; }
};

class Derived: public Base
{
private:
	int doubled_value;

public:
	// Derived No-args Constructor. It will initialize No-args Base Construtor
	Derived() : Base(), doubled_value{0} {cout << "Derived No-args Constructor Called" << endl; } 

	// Derived No-args Constructor. It will initialize Base Construtor
	Derived(int x): Base(x), doubled_value{x * 2} { cout << "int Derived Constructor Called" << endl; } 

	// Derived Destructor Called
	~Derived() { cout << "Derived Destructor Called" << endl; }

	// Derived Copy Constructor
	Derived(const Derived &other)
	: Base(other), doubled_value{other.doubled_value} 
	{
		cout << "Derived Copy Constructor Called" << endl;
	}

	// Derived Assignment Operator
	Derived &operator=(const Derived &rhs)
	{
		if(this != &rhs)
		{
			Base::operator=(rhs);
			doubled_value = rhs.doubled_value; 
		}

		cout << "Derived Assignment Operator" << endl;
		return *this;
	}

};

int main()
{
	//Base b{100}; // Overloaded Constructor - Derived 
	//Base b1 {b}; // Copy Constructor - Derived 
	//b = b1; 	 // Assignmnet Operator - Derived 

	cout << endl;

	Derived d{100}; // Overloaded Constructor - Derived and Base
	Derived d1 {d}; // Copy Constructor - Derived and Base
	d = d1; 		// Assignmnet Operator - Derived and Base

	cout << endl;

	return 0;
}

