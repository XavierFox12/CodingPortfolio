/***********************************************************
* Name:		Xavier Fox
*
* Email:	xf899715@ohio.edu
*
* File Name:	numbers.h
*
* Description:	Header and implementation file that allows
*		the user to add data to the array, resize
*		the array if data exceeds the capacity.
*		It also allows the user to remove the last
*		element in the array, as well as display
*		all of the data in the array, and allows
*		the user to use the = operator
*
* Date:		2/8/17
*
* Lab #:	102
************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

#ifndef NUMBERS_H
#define NUMBERS_H
using namespace std;

class Numbers {
	public:
		Numbers();
		~Numbers();
		Numbers(const Numbers& other);
		void add(unsigned long num);
		void resize();
		void remove_last();
		void display(std::ostream& outs)const;
        	void operator =(const Numbers& other);
	private:
		unsigned long *data;
		std::size_t used;
		std::size_t capacity;
};
#endif

//Default Constructor
Numbers::Numbers()
{
    data = new unsigned long[5];
    capacity = 5;
    used = 0;
}

//Destructor
Numbers::~Numbers()
{
	delete[] data;
}

//Copy Constructor
Numbers::Numbers(const Numbers& other)
{
	used = other.used;
	capacity = other.capacity;
	data = new unsigned long[capacity];
	for (int i = 0; i < used; i++)
	{
		data[i] = other.data[i];
	}
}

//Adds numbers to the array
void Numbers::add(unsigned long num)
{
    if (used == capacity)
    {
        resize();
    }
    data[used] = num;
    ++used;
}

//Resizes the array by 5
void Numbers::resize()
{
    unsigned long *tmpptr;
    tmpptr = new unsigned long[capacity + 5];
    copy(data, data + used, tmpptr);
    delete[] data;
    data = tmpptr;
    capacity += 5;
}

//Removes the last number in the array
void Numbers::remove_last()
{
    --used;
}

//Displays all of the numbers in the array
void Numbers::display(ostream& outs)const
{
    for (size_t i = 0; i < used; i++)
    {
        outs << data[i] << " ";
    }
    outs << endl;
}

//Allows the Numbers variables to use the = operator
void Numbers::operator =(const Numbers& other)
{
    if (this == &other)
    {
        return;
    }
    used = other.used;
    if (other.capacity != capacity)
    {
        delete[] data;
        capacity = other.capacity;
        data = new unsigned long[capacity];
    }
    copy(other.data, other.data + used, data);
}
