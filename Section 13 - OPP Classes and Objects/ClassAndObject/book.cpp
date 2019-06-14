#include "book.h"

// Defining Default Constructor
Book::Book(std::string title_val, std::string author_val, int pages_val, double cost_val)
: title {title_val}, author {author_val}, pages {pages_val}, cost {cost_val} 
{
	std::cout << "Constructor called" << std::endl;
}

// Defining Copy Constructor

Book::Book(const Book &source)
: Book{source.title, source.author, source.pages, source.cost}
{
	std::cout << "Copy constructor - made a copy of " << source.title << std::endl;
}

// Defining Destructor

Book::~Book() { std::cout << "Destructor called" << std::endl; }

// Defining all the functions
std::string Book::get_title() { return title; }
std::string Book::get_author() { return author; }
int Book::get_pages() { return pages; }
double Book::get_cost() { return cost; }

void Book::set_title(std::string new_title) { title = new_title; }
void Book::set_author(std::string new_author) { author = new_author; }
void Book::set_pages(int new_pages) { pages = new_pages; }
void Book::set_cost(double new_cost) { cost = new_cost; }

void Book::print_info()
{
	std::cout << "The title is: " << title << std::endl;
	std::cout << "The author is: " << author << std::endl;
	std::cout << "Number of pages: " << pages << std::endl;
	std::cout << "Cost: $" << cost << std::endl;

	return;
}