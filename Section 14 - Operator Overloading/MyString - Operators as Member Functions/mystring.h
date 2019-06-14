#pragma once 
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class MyString
{
	private:
		// Attributes
		char *str; // Pointer to a C-Stle String (char[])

	public:
		// Constructors
		MyString(); // No-args Constructor
		MyString(const char *s); // Overloaded and Delegated Constructor
		MyString(const MyString &source); // Deep Copy Constructor
		~MyString(); // Destructor

		// Overloading Opertors
		MyString &operator=(const MyString &rhs); // Deep Copy Assignment Operator
		MyString &operator=(MyString &&rhs); // Move Assignment Operator
		MyString operator-() const; // Make Lowecase Operator
		MyString operator+(const MyString &rhs) const; // Concatenate Operator
		bool operator==(const MyString &rhs) const; // Equality Operator

		// Methods
		void display() const;
		int get_length() const; // Returns the length of the string
		const char *get_str() const; // Returns a pointer to the string
};

#endif // _MYSTRING_H_