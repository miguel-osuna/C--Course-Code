#include <iostream>
#include "shoe.h"
using namespace std;

int main()
{	
	// Material, Color, Size, Cost
	Shoe my_shoe{"Leather", "Black", 10, 100.0};
	display_shoe_info(my_shoe);
	display_shoe_number();

	{
		Shoe your_shoe{"Plastic", "White", 9, 20.0};
		display_shoe_info(your_shoe);
		display_shoe_number();
	} // Destructor called: shoes = shoes - 1

	display_shoe_number();

	return 0;
}