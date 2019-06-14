/*
	Purpose: Using Custom Deleters
	Author: Miguel Osuna
	Date: 6/5/2019
*/

#include <iostream>
#include <memory>

class Test
{
private:
	int data;
public:
	Test() :data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
	Test(int data): data{data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
	int get_data() const { return data; }
	~Test() { std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

void my_deleter(Test *ptr)
{
	std::cout << "\tUsing custom deleter" << std::endl;
	delete ptr;
}

int main()
{
	{
		// Using a Function
		std::shared_ptr<Test> ptr1 { new Test{200}, my_deleter };
	} // End of local scope; my_deleter is called

	std::cout << "===========================" << std::endl;

	{
		// Using Lambda Expression
		std::shared_ptr<Test> ptr2 (new Test{100}, 
		[] (Test *ptr)  
		{
			std::cout << "\tUsing my custom lambda deleter" << std::endl;
			delete ptr;
		});
	} // End of local scope; my_deleter is not called

	return 0;
}