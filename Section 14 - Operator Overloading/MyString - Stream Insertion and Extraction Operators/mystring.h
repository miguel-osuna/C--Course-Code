#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class MyString
{

	friend std::ostream &operator<<(std::ostream &os, const MyString &rhs);
	friend std::istream &operator>>(std::istream &in, MyString &rhs);
	
	friend bool operator==(const MyString &lhs, const MyString &rhs); // Equality Operator Global Function
	friend MyString operator-(const MyString &rhs); // Lowecase Operator Global Function
	friend MyString operator+(const MyString &lhs, const MyString &rhs); // Concatenation Operator Global Function
	friend bool operator<(const MyString &lhs, const MyString &rhs); // Less Than Operator Global Function
	friend bool operator>(const MyString &lhs, const MyString &rhs); // Greater Than Operator Global Function

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
