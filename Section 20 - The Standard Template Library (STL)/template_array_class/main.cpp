/*
	Purpose: Generic Template Array Class. C++11 already has a std::array class
	Author: Miguel Osuna
	Date: 6/9/2019
*/

#include <iostream>
#include <string>

// Generic Array Class
// It needs an 'int' value to create the array
template<int N, typename T>
class Array
{
	friend std::ostream &operator<<(std::ostream &os, const Array<N, T> &obj)
	{
		os << "[ ";
		for(const auto &val: obj.values)
			os << val << " ";
		os << "]";
		return os;
	}

private:
	int size {N};
	T values[N]; // The 'N' needs to be known at compile-time
	
public:
	Array() = default;
	Array(T init_value)
	{
		for(auto &item: values)
			item = init_value;
	}

	void fill(T val)
	{
		for(auto &item: values)
			item = val;
	}

	int get_size() const 
	{
		return size;
	}

	// Overloaded subscript operator
	T &operator[](T index)
	{
		return values[index];
	}
};

int main()
{
	Array<5, int> nums;
	std::cout << "The size of nums is: " << nums.get_size() << std::endl;
	std::cout << nums << std::endl;

	nums.fill(0);
	std::cout << "The size of nums is: " << nums.get_size() << std::endl;
	std::cout << nums << std::endl;

	nums.fill(10);
	std::cout << nums << std::endl;

	nums[0] = 1000;	// nums.operator[](0)
	nums[3] = 2000;
	std::cout << nums << std::endl;

	Array<100, double> nums2 {1};
	std::cout << "The size of nums2 is: " << nums2.get_size() << std::endl;
	std::cout << nums2 << std::endl;

	Array<10, std::string> names{};
	names.fill("Test");
	std::cout << "The names are: " << names << std::endl;	

	return 0;
}









