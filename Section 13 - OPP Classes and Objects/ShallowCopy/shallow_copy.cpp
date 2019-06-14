/*
	Section 13: 
	Copy Constructor - Shallow Copy 
	Note: This program will crash
*/

#include <iostream>
using namespace std;

// Shallow

class Shallow
{
private:
    // attributes

    int *data;
public:
    // methods
    int get_data_value() { return *data; }
    void set_data_value(int d) { *data = d; }

    // Constructor
    Shallow(int d);
    // Copy Constructor
    Shallow(const Shallow &source);
    // Destructor
    ~Shallow();
};

// Shallow Definitions

// Constructor Definition
Shallow::Shallow(int d)
{
        // allocate storage on the heap
    data = new int;
    *data = d;
    cout << "Constructor Called\n" << endl;
}

// Copy Constructor
// In this case, with the copy constructor, only the pointer is copied, not what is pointing to!
// Problem: source and the newly created object BOTH point to the SAME data area
Shallow::Shallow(const Shallow &source)
: data{source.data} {
cout << "Copy Constructor Called - Shallow\n" << endl;
}

// Destructor
Shallow::~Shallow()
{
    // free dynamic allocated storage
    delete data;
    cout << "Destructor Called\n" << endl;
}

// This function creates a copy of a Shallow object, calling the Copy Constructor to do so
void display_shallow(Shallow s)
{
    cout << s.get_data_value() << "\n" << endl;
}

// This main will likely crash
int main()
{
    // This will call the Constructor, allocating *data member to 100
    Shallow object1 {100};

    // This will create a Shallow copy, calling the Copy Constructor and copying the
    // pointer 'data'
    // Also, when the local scope ends, it will call the Destructor, and free the memory allocated
    // This is where the problem appears
    display_shallow(object1);

    // This will create a Shallow copy, calling the Copy Constructor again, and copying the already freed 
    // pointer
    Shallow object2 {object1};

    // Sets the value 1000 to the heap memory location pointer *data points to    
        object2.set_data_value(1000);

} // When the scope is ended, the compiler will try to call the Destructor on the 2 objects that were allocated previously, originating a crash