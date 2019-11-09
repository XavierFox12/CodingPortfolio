/***********************************************************
* Name:		Xavier Fox
*
* Email:	xf899715@ohio.edu
*
* File Name:	library.cc
*
* Description:	The implementation file for the Library
*		class, which has functions that can add
*		books, show all the books, return the number
*		of books, and number of pages. It is also
*		able to sort the library by date and title,
*		as well as find the title and author of the
*		book. The class will also be able to remove
*		a book, and upload and save a file.
*
* Date:		1/24/17
*
* Lab #:	102
************************************************************/

#include "library.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

//Default Constructor
Library::Library()
{
	used = 0;
}

//Allows the user to enter an additional book
void Library::addbook(Book& b1)
{
	data[used] = b1;
	used++;
}

//Shows all of the books that are in the library
void Library::showall(ostream& outs)const
{
	size_t i;

	for (i = 0; i < used; i++)
	{
		outs << data[i] << endl;
	}
}

//Shows the number of pages in the library
int Library::numpages()const
{
	int totalPages = 0;
	size_t i;

	for (i = 0; i < used; ++i)
	{
		totalPages += data[i].get_pages();
	}

	return totalPages;
}

//Sorts the library by the copyright date in ascending order
void Library::sort_by_date()
{
	Book tmp;
	bool done;
	done = false;
	while (!done)
	{
		done = true;
		for (size_t i = 0; i < used-1; ++i)
		{
			if (data[i].get_copyright() > data[i+1].get_copyright())
			{
				tmp = data[i];
				data[i] = data[i+1];
				data[i+1] = tmp;
				done = false;
			}
		}
	}
}

//Sorts the library by title in ascending order
void Library::sort_by_title()
{
	Book tmp;
	bool done;
	done = false;
	while (!done)
	{
		done = true;
		for (size_t i = 0; i < used-1; ++i)
		{
			if (data[i].get_title() > data[i+1].get_title())
			{
				tmp = data[i];
				data[i] = data[i+1];
				data[i+1] = tmp;
				done = false;
			}
		}
	}
}

//Searches for a book given the title, and outputs all the information
//on that book
void Library::find_title(const string& target)const
{
	size_t i;

	for (i = 0; i < used; i++)
	{
		if (data[i].get_title() == target) {
			cout << data[i];		
			return;
		}
	}
	cout << "Could not find any books with that title. Try again" << endl << endl;
}

//Searches for a book given the author, and outputs all the information
//on that book
void Library::find_author(const string& target)const
{
	size_t i;
	bool found = false;

	for (i = 0; i < used; i++)
	{
		if (data[i].get_author() == target)
		{
			cout << data[i];
			found = true;
		}
	}

	if (!found)
		cout << "Could not find any books by that author. Try again" << endl << endl;
}

//Removes a book from the library
void Library::remove(const string& target)
{
	size_t i;

	for (i = 0; i < used; i++)
	{
		if (data[i].get_title() == target)
		{
			data[i] = data[used-1];
			--used;
			return;
		}
	}

	cout << "Could not find any books to remove with that title. Try again" << endl << endl;
}

//Loads the .txt file into an array
void Library::load(istream& ins)
{
	Book b1;
	
	ins >> b1;
	while (!ins.eof() && used < SIZE)
	{
		addbook(b1);
		ins >> b1;
	}
}

//Saves all of the changes into a different file
void Library::save(ostream& outs)const
{
    	for (size_t i = 0; i < used; i++)
    	{
        	outs << data[i] << endl;
    	}
}
