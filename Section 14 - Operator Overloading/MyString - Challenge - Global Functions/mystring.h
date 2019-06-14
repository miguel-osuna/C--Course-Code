#pragma once 
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class MyString
{
		friend MyString operator-(MyString &obj); // Unary Minus Operator
		friend MyString &operator++(MyString &obj); // Pre-increment Operator
		friend MyString operator++(MyString &obj, int); // Post-increment Operator
		friend bool operator==(const MyString &lhs, const MyString &rhs); // Equality Operator
		friend bool operator!=(const MyString &lhs, const MyString &rhs); // Inequality Operator
		friend bool operator<(const MyString &lhs, const MyString &rhs); // Less Than Operator
		friend bool operator>(const MyString &lhs, const MyString &rhs); // Greater Than Operator
		friend MyString operator+(const MyString &lhs, const MyString &rhs); // Concatenation Operator
		friend MyString &operator+=(MyString &lhs, const MyString &rhs); // Concatenation Equal Operator
		friend MyString operator*(const MyString &lhs, const int &number); // Repeat Operator
		friend MyString &operator*=(MyString &lhs, const int &number); // Repeat Equal Operator

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

		// Methods
		void display() const;
		int get_length() const; // Returns the length of the string
		const char *get_str() const; // Returns a pointer to the string
};

#endif // _MYSTRING_H_