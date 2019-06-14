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
		MyString(const char *s); // Delegated Constructor
		MyString(const MyString &source); // Deep Copy Constructor
		~MyString(); // Destructor

		// Methods
		void display() const;
		int get_length() const; // Returns the length of the string
		const char *get_str() const; // Returns a pointer to the string
};


#endif // _MYSTRING_H_