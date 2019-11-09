/*************************************************************
* Name:		Xavier Fox
*
* Email:	xf899715@ohio.edu
*
* File Name:	library.h
*
* Description:	Sets up the Library class, which has
*		functions that can add books, show all the
*		books, return the number of books, and number
*		of pages. It is also able to sort the library
*		by date and title, as well as find the title
*		and author of the book. The class will also
*		be able to remove a book, and upload and
*		save a file.
*
* Date:		1/24/17
*
* Lab #:	102
**************************************************************/

#include "book.h"
#ifndef LIBRARY_H
#define LIBRARY_H

class Library
{
public:
	Library();
    	static const std::size_t SIZE = 100;
	void addbook(Book& b1);
	void showall(std::ostream& outs)const;
	size_t size()const {return used;}
	int numpages()const;
	void sort_by_date();
	void sort_by_title();
    	void find_title(const std::string& target)const;
	void find_author(const std::string& target)const;
	void remove(const std::string& target);
	void load(std::istream& ins);
	void save(std::ostream& outs)const;
private:
    Book data[SIZE];
    std::size_t used;
};

#endif

/* addbook (tmp)
   showall (cout)
 */
