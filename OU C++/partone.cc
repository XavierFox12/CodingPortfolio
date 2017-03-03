/***********************************************************
* Name:		Xavier Fox
*
* Email:	xf899715@ohio.edu
*
* File Name:	partone.cc
*
* Description:	Tests static and automatic variables by
*		calling the pretty function, which declares
*		the static or automatic variable x. The 
*		variable then goes through a loop that
*		prints out a *.
*
* Date:		2/1/17
*
* Lab #:	102
************************************************************/

#include <iostream>

using namespace std;

void pretty();

int main()
{
	for (int i = 0; i != 6; ++i)
	{
		pretty();
	}
}

void pretty () {
	auto int x = 0;
	
	x++;
	
	for (int i = 0; i < x; ++i)
	{
		cout << '*';
	}

	cout << endl;
}
