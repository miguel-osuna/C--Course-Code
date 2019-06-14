#include <cstring>
#include <iostream>
#include "mystring.h"

/* For calls like: MyString a;
We dynamically allocate memory for
the pointer, with the size of char[1]

The null terminator is used to avoid 
checking for it laater */
MyString::MyString()
: str{nullptr} 
{ 
	str = new char[1];
	*str = '\0';
}

/* For calls like: MyString a {"Text"}; 
In this case, we take the pointer of the C-string
and asign it to a.str

The null terminator is automatically added */
MyString::MyString(const char *s)
: str{nullptr} 
{
 	// Checks in case for a nullptr
	if(s == nullptr)
	{
		str = new char[1];
		*str = '\0';
	}
		
	else 
	{
		str = new char[std::strlen(s) + 1]; // TWe add another character space for the null terminator
		std::strcpy(str, s); // It automatically copies the null terminator to str c-style string ('\0'), one character
							 // by one, that is why we don't derreference the pointer
	}
}

/* For calls like: MyString b {a};

In this case, we make a copy of the content
source.str is pointing to */
MyString::MyString(const MyString &source)
:str{nullptr}
{
	str = new char[std::strlen(source.str) + 1];
	std::strcpy(str, source.str);
}

// Destructor
MyString::~MyString()
{
	delete [] str;
}

/* Deep Copy Assignment Operator
It will create an inside MyString object
MyString& returns a reference to the object '*this'
This is always the best practice*/
MyString &MyString::operator=(const MyString &rhs)
{
	// If the pointer to the current object 'this' has the address of the object 'rhs', then
	// it has the same content, therefore we derreference *this to return the object
	if(this->str == rhs.str)
		return *this;

	// We deallocate memory for the deep copy of rhs
	delete [] this->str;
	this->str = new char[std::strlen(rhs.str) + 1];
	std::strcpy(this->str, rhs.str);
	return *this;
}

/*Move Assingment Operator
It will create a temporary MyString object so it's pointer
can be stolen for the current object*/
MyString &MyString::operator=(MyString &&rhs)
{
	if(this == &rhs) // Check for self assignment
		return *this; // Return current object
	
	delete [] this->str; // Deallocate current storage
	this->str = rhs.str;// Steal rhs pointer. This is where the efficiency it's reflected

	rhs.str = nullptr; // Null out the rhs object

	return *this; // Return current object
}

void MyString::display() const
{
	std::cout << str << ":" << get_length() << std::endl;
}

int MyString::get_length() const
{
	return std::strlen(str);
}

/*The first 'const' means that the return value is a Read-Only value, and
if the user tries to change it after it's been returned, it will throw an error.

The second 'const' guarantees that the function will not modify any object attribute*/
const char *MyString::get_str() const
{
	return str;
}

// Unary Minus Operator
MyString &MyString::operator-()
{
	//char *buffer = new char [std::strlen(this->str) + 1];
	for(size_t i = 0; i < std::strlen(this->str); i++)
		this->str[i] = std::tolower(this->str[i]);
	return *this;
}

// Pre-increment Operator
MyString &MyString::operator++()
{
	for(size_t i = 0; i < std::strlen(this->str); i++)
		this->str[i] = std::toupper(this->str[i]);
	return *this;
}

// Post-increment Operator
MyString MyString::operator++(int num) 
{
	MyString temp {*this}; // Make a copy
	operator++(); // Call pre-increment;
	return temp; // Return old value
}

// Equality Operator
bool MyString::operator==(const MyString &rhs) const
{
	return (std::strcmp(this->str, rhs.str) == 0);	
}

// Inequality Operator
bool MyString::operator!=(const MyString &rhs) const
{
	return (std::strcmp(this->str, rhs.str) != 0);
}

// Less Than Operator
bool MyString::operator<(const MyString &rhs) const 
{
	return (std::strcmp(this->str, rhs.str) < 0);
}

// Greater Than Operator
bool MyString::operator>(const MyString &rhs) const
{
	return (std::strcmp(this->str, rhs.str) > 0);
}

// Concatenation Operator
MyString MyString::operator+(const MyString &rhs) const
{
	char *buffer = new char [std::strlen(this->str) + std::strlen(rhs.str) + 1];
	std::strcpy(buffer, this->str);
	std::strcat(buffer, rhs.str);
	MyString temp{buffer};
	delete [] buffer;
	return temp;
}

// Concatenation Equal Operator
MyString &MyString::operator+=(const MyString &rhs)
{
	*this = *this + rhs;
	return *this;
}

// Repeat Operator
MyString MyString::operator*(const int &number) const
{
	char *buffer = new char [(std::strlen(this->str) * number) + 1];
	std::strcpy(buffer, this->str);
	for(int i = 0; i < number; i++)
		std::strcat(buffer, this->str);
	MyString temp {buffer};
	delete [] buffer;
	return temp;
}

// Repeat Equal Operator
MyString &MyString::operator*=(const int &number)
{
	*this = *this * number;
	return *this;
}
