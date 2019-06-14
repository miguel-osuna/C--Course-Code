#include "movies.h"

// Consctructor
Movies::Movies()
{ }

// Destructor
Movies::~Movies()
{ }

// This function displays the movies available in the 'Movies' object
void Movies::display_movies()
{
	if(movies.size() != 0)
	{
		for(auto &mov: movies)
		{
			mov.display_info();
			std::cout << "|==============================================================|" << std::endl;
		}
	}

	else
		std::cout << "Sorry, no movies to display" << std::endl;
}

/* This function checks if a movie has been repeated, 
and if so, it returns false, otherwise, it adds the movie 
to the object 'Movies'*/
bool Movies::add_movie(std::string name, std::string rating, int views)
{

	// for(size_t i = 0; i < movies.size(); i++)
	for(Movie &mov: movies)
		if(mov.get_name() == name)
			return false;

	movies.push_back(Movie{name, rating, views});

	return true;
}

/* This function checks if a movie is available in the list, 
if not, it returns false, otherwise, it increments the views variable
of the 'Movie' by 1*/
bool Movies::view_incremented(std::string name)
{
	for(Movie &mov: movies)
	{
		if(mov.get_name() == name)
		{
			mov.increment_views();
			return true;
		}
	}

	return false;
}

void add_movie(Movies &movies, std::string name, std::string rating, int views)
{
	if(movies.add_movie(name, rating, views))
		std::cout << "Movie added" << std::endl;
	else
		std::cout << "Movie already exists" << std::endl;
}

void increment_views(Movies &movies, std::string name)
{
	if(movies.view_incremented(name))
		std::cout << "Views incremented" << std::endl;
	else
		std::cout << "Movie doesn't exist" << std::endl;
}