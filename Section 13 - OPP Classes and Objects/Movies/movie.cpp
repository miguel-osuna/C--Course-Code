#include "movie.h"

// Delegated Constructor
Movie::Movie(std::string name, std::string rating, int views)
: name{name}, rating{rating}, views{views} {
}

// Copy Constructor
Movie::Movie(const Movie &source)
: Movie{source.name, source.rating, source.views} {
} 

// Destructor
Movie::~Movie()
{ }

// This functions displays the info of the movie object created
void Movie::display_info()
{
	std::cout << "| Movie's name: " << get_name() << " | Rating: " << get_rating() << " | Views: " << get_views() << " |" << std::endl;
}