#include <iostream>
#include <string>
#include "book.h"

using namespace std;

void print_everything(Book new_book)
{
	cout << "Title: " << new_book.get_title() << endl;
	cout << "Author: " << new_book.get_author() << endl;
	cout << "Pages: " << new_book.get_pages() << endl;
	cout << "Cost: " << new_book.get_cost() << endl;
}

void print_everything(Book *new_book)
{
	cout << "Title: " << new_book->get_title() << endl;
	cout << "Author: " << new_book->get_author() << endl;
	cout << "Pages: " << new_book->get_pages() << endl;
	cout << "Cost: " << new_book->get_cost() << endl;
}

int main()
{
	Book otherBook("Maida Celina", "Another Best Book Ever", 2000, 400);
	print_everything(otherBook);

	Book *bookPtr {nullptr};
	bookPtr = new Book("Miguel Osuna", "The Best Book Ever", 1000, 300);
	print_everything(bookPtr);

	delete bookPtr;

	return 0;
}