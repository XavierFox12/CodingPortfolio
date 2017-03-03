/***********************************************************
* Name:		Xavier Fox
*
* Email:	xf899715@ohio.edu
*
* File Name:	parttwo.cc
*
* Description:	Tests Dynamic Variables by setting up a
*		new pointer variable, which prints out the
*		address of the new int variable, and the
*		address of the pointer itself. It then goes
*		through a loop to print out the number, and
*		where that number is stored.
*
* Date:		2/1/17
*
* Lab #:	102
************************************************************/

#include <iostream>

using namespace std;

int main()
{
	int *ptr;
	
	ptr = new int;

	cout << ptr << endl;

	cout << &ptr;

	*ptr = 2401;

	for (int i = 0; i !=100000; ++i)
	{
		--(ptr);
		cout << *ptr << " is stored at " << ptr << endl;
	}
}
