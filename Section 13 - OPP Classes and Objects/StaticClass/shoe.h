#ifndef _SHOE_H_
#define _SHOE_H_
#include <iostream>
#include <string>

class Shoe
{
	private:
		// attrbiutes
		std::string material;
		std::string color;
		int size;
		double cost;
		// This will chage in the Constructor or Destructor
		static int shoes;

	public:
		// methods
		// methods for const/non-const objects
		std::string get_material() const { return this->material; }
		std::string get_color() const { return this->color; }
		int get_size() const { return this->size; }
		double get_cost() const { return this->cost; }

		void set_material(std::string material) { this->material = material; }
		void set_color(std::string color) { this->color = color; }
		void set_size(int size) { this->size = size; }
		void set_cost(double cost) { this->cost = cost; }

		// It only has access to static variables. 
		// This cannot be used for static member functions
		static int get_num_shoes() { return shoes; } 

		// constructors
		Shoe(std::string material = "None", std::string color = "None", int size = 0, double cost = 0.0);
		Shoe(const Shoe &source);
		~Shoe();
};

void display_shoe_number();
void display_shoe_info(const Shoe &source);

#endif // _SHOE_H_
