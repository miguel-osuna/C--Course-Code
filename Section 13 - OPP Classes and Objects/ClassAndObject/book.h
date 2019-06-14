#ifndef _BOOK_H_
#define _BOOK_H_
#include <string>
#include <iostream>

// We create a book class with all the function prototypes/declarations
class Book
{
	private:
		// Attributes
		std::string title;
		std::string author;
		int pages;
		double cost;

	public:
		// Default Constructor
		Book(std::string title_val = "None", std::string author_val = "Someone", int pages_val = 0, double cost_val = 0);

		// Copy Constructor
		Book(const Book &source);

		// Destructor
		~Book();

		// Methods
		std::string get_title();
		std::string get_author();
		int get_pages();
		double get_cost();

		void set_title(std::string new_title);
		void set_author(std::string new_author);
		void set_pages(int new_pages);
		void set_cost(double new_cost);
		void print_info();

};

#endif //_BOOK_H_