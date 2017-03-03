/***********************************************************
* Name:		Xavier Fox
*
* Email:	xf899715@ohio.edu
*
* File Name:	book.cc
*
* Description:	The implementation file for the Book class.
*
* Date:		1/24/17
*
* Lab #:	102
************************************************************/

#include "book.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Default constructor
Book::Book()
{
	title = "N/A";
	author = "N/A";
	year = 0;
	pages = 0;
}

//Asks the user for the title, author, copyright year,
//and number of pages for the book
void Book::input(istream& ins)
{
	if (&ins == &cin)
	{
		if(ins.peek() == '\n' || ins.peek() == '\r')
		    ins.ignore();

		cout << "Title: ";
		getline(ins, title);

		cout << "Author: ";
		getline(ins, author);

		cout << "Copyright Year: ";
		ins >> year;

		cout << "Number of Pages: ";
		ins >> pages;
	}
	else
	{
		if(ins.peek() == '\n' || ins.peek() == '\r')
		    ins.ignore();

		getline(ins, title);
		
		getline(ins, author);
		
		ins >> year;
		
		ins >> pages;
	}
}

//Outputs the title, author, copyright year,
//and number of pages for the book
void Book::output(ostream& outs)const
{
	if (&outs == &cout)
	{
		outs << "Title:     " << title << endl
		     << "Author:    " << author << endl
		     << "Copyright: " << year << endl
		     << "Pages:     " << pages << endl;
	}
	else
	{
		outs << title << endl
		     << author << endl
		     << year << endl
		     << pages;
	}
}

//Returns the title of the book
string Book::get_title()const
{
	return title;
}

//Returns the author of the book
string Book::get_author()const
{
	return author;
}

//Returns the copyright year of the book
int Book::get_copyright()const
{
	return year;
}

//Returns the number of pages of the book
int Book::get_pages()const
{
	return pages;
}

//Notices the input operator, and passes it to the input function
istream& operator >> (istream& ins, Book& b1)
{
	b1.input(ins);
	return ins;
}

//Notices the ouput operator, and passes it the oputput function
ostream& operator << (ostream& outs, const Book& b1)
{
	b1.output(outs);
	return outs;
}
