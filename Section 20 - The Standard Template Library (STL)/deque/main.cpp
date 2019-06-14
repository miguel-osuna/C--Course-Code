#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

template <typename T>
void display(const std::deque<T> &d);
bool isPalindrome(const std::string &str);

int main()
{
	std::deque<std::string> palindromes 
										{"A but tuba", 
										 "A car, a man, a maraca",
										 "Able was I ere I saw Elba"
										 "A Toyota! Race fast, safe car! A Toyota!"
										};

	for(auto &str: palindromes)
		if(isPalindrome(str))
			std::cout << "\nString: '" << str << "' is a palindrome" << std::endl;

	return 0;
}

template <typename T>
void display(const std::deque<T> &d)
{
	std::cout << "[ ";
	for(const auto &elem: d)
		std::cout << elem << " ";
	std::cout << "]";
}

bool isPalindrome(const std::string &str)
{
	std::deque<char> d;

	// Add all the string characters that are alpha to the back of the deque in uppe case
	for(auto c: str)
		if(std::isalpha(c))
			d.push_back(std::toupper(c));

	char c1{};
	char c2{};

	while(d.size() > 1)
	{
		c1 = d.front();
		c2 = d.back();

		d.pop_front();
		d.pop_back();

		if(c1 != c2)
			return false;
	}

	return true;
}
