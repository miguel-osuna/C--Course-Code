#include "shoe.h"

// We access to the static variable to initialize it
int Shoe::shoes{0};

Shoe::Shoe(std::string material, std::string color, int size, double cost)
: material{material}, color{color}, size{size}, cost{cost} {
	++shoes;
}

Shoe::Shoe(const Shoe &source)
: Shoe{source.material, source.color, source.size, source.cost} {
}

Shoe::~Shoe()
{
	--shoes;
}

void display_shoe_number()
{
	std::cout << "Number of shoes: " << Shoe::get_num_shoes() << std::endl;
	std::cout << std::endl;
}

void display_shoe_info(const Shoe &source)
{
	std::cout << "Shoe material: " << source.get_material() << std::endl;
	std::cout << "Shoe color: " << source.get_color() << std::endl;
	std::cout << "Shoe size: " << source.get_size() << std::endl;
	std::cout << "Shoe cost: " << source.get_cost() << std::endl;
	std::cout << std::endl;
}
