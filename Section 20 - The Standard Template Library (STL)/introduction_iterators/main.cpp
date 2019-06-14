/*
	Purpose: Introduction to Iterators
	Author: Miguel Osuna
	Date: 6/9/2019
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

// Display any vector of 'T' type using range-based for loop
template<typename T>
void display(const std::vector<T> vec)
{
	std::cout << "[ ";
	for(auto &i: vec)
		std::cout << i << " ";
	std::cout << "]";
}

int main()
{
	std::cout << "Displaying with iterators" << std::endl;
	std::vector<double> vec = {1.2, 3.4, 4.5, 5.6};	

	// An iterator is like a pointer, but in reality is an object
	std::vector<double>::iterator it = vec.begin();

	std::cout << "vec[0] = " << *it << std::endl;	// 1.2
	std::cout << "vec[1] = " << *++it << std::endl;  // 3.4

	it += 1;
	std::cout << "vec[3] = " << *it << std::endl;	// 4.5

	it = vec.end() - 1;
	std::cout << "vec[1] = " << *it << std::endl;	// 5.6

	std::cout << "vec[2] = " << *--it << std::endl;	// 4.5

	// Set vector elements to 0
	it = vec.begin();
	for(; it != vec.end(); it++)
		*it = 0.0;

	display(vec);

	return 0;
}
