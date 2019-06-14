/*
	Section 13: 
	Copy Constructor - Deep Copy 
	Note: This program will not crash
*/
#include <iostream>
using namespace std;

class Deep
{
private:
	// attributes
	int *data;
public:
	// methods
	int get_data() { return *data; }
	void set_data(int d) { *data = d; }

	// constructors
	// Constructor
	Deep(int d);
	// Copy Constructor
	Deep(const Deep &source);
	// destructors
	~Deep();
};

// Constructor
Deep::Deep(int d)
{
	// We allocate storage
	data = new int;
	*data = d;
	cout << "Constructor Called\n" << endl;
}

// Copy Constructor
// Now we don't have to initialize
// But we have to create a new pointer
// Deep Copy crates a new storage and copies values
Deep::Deep(const Deep &source)
// : Deep{*source.data}
{
	// The new pointer will have a new address
	data = new int;
	// We derreference the original pointer to access to the value on the heap
	*data = *source.data;
	cout << "Copy Constructor Called - Deep Copy\n" << endl;
}

// Destructor
// This will be called at the end of the scope
// So, it will delete the newest pointer
Deep::~Deep()
{
	// Frees data allocatd by the constructor
	delete data;
	cout << "Destructor Called\n" << endl;
}

// This function will make a copy
// When this goes out of scope, it will call the Destructor
// for the newly created object, therefore, there will be no
// problem
void display_deep(Deep s)
{
	cout << s.get_data() << endl;
}

int main()
{
	// Creates a new object
	Deep object1{100};
	// Creates a copy of object 1 and displays the content
	// With a new pointer and new memory location for the data
	// Then deletes the copy without affecting the original one
	display_deep(object1);

	// Set data to 1000
	object1.set_data(1000);

	// Creates a new copy of object1
	// With a new pointer and new memory location for the data
	Deep object2 {object1};

	return 0;

} //Destructor called for both objects, starting with the last one