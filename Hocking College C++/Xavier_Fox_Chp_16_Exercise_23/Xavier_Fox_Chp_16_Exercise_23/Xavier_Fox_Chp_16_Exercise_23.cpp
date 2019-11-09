/* Program: Xavier_Fox_Chp_16_Exercise_23.cpp
   Programmer: Xavier Fox
   Date: 28 Apr. 2015
   Purpose: To keep track and update the friendly hardware
   store inventory.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void loadData(vector<int>& itemID, vector<string>& itemName, vector<int>& pOrdered,
			  vector<int>& pInStore, vector<int>& pSold, vector<double>& manufPrice,
			  vector<double>& sellingPrice, ifstream& inp);
void sortData(vector<int>& itemID, vector<string>& itemName, vector<int>& pOrdered,
			  vector<int>& pInStore, vector<int>& pSold, vector<double>& manufPrice,
			  vector<double>& sellingPrice, int size);
void displayMenu(vector<int>& itemID, vector<string>& itemName, vector<int>& pOrdered,
			  vector<int>& pInStore, vector<int>& pSold, vector<double>& manufPrice,
			  vector<double>& sellingPrice, int size);
void inStore(vector<string> itemName, vector<int> pInStore, int size);
void sellItem(vector<string>& itemName, vector<int>& pOrdered, vector<int>& pInStore,
			  vector<int>& pSold, vector<double>& sellingPrice, int size);
void checkPrice(vector<string> itemName, vector<double> sellingPrice, int size);
void print(vector<int> itemID, vector<string> itemName, vector<int> pOrdered,
		   vector<int> pInStore, vector<int> pSold, vector<double> manufPrice,
		   vector<double> sellingPrice, int size);
int binarySearch(vector<string>& list, string searchItem, int size);

int main()
{
	vector<int> itemID;
	vector<string> itemName;
	vector<int> pOrdered;
	vector<int> pInStore;
	vector<int> pSold;
	vector<double> manufPrice;
	vector<double> sellingPrice;
	int size;
	ifstream inFile;

	inFile.open("E:\\SP2015\\C++\\Ch16_Ex23Data.txt");
	if (!inFile)
	{
		cout << "Cannot find Ch16_Ex23Data.txt" << endl
			 << "   The Program terminates    " << endl << endl;
		return 1;
	}

	loadData(itemID, itemName, pOrdered, pInStore, pSold, manufPrice,
			 sellingPrice, inFile);

	size = itemID.size();

	sortData(itemID, itemName, pOrdered, pInStore, pSold, manufPrice,
			 sellingPrice, size);
	displayMenu(itemID, itemName, pOrdered, pInStore, pSold, manufPrice,
				sellingPrice, size);

	return 0;
}

// Loads the data into the vector
void loadData(vector<int>& itemID, vector<string>& itemName, vector<int>& pOrdered,
			  vector<int>& pInStore, vector<int>& pSold, vector<double>& manufPrice,
			  vector<double>& sellingPrice, ifstream& inp)
{
	int id, ordered;
	string item;
	double manufacturingPrice, selling;

	inp >> id;
	inp.ignore();
	getline(inp, item);
	inp >> ordered >> manufacturingPrice >> selling;

	while (inp)
	{
		itemID.push_back(id);
		itemName.push_back(item);
		pOrdered.push_back(ordered);
		pInStore.push_back(ordered);
		pSold.push_back(0);
		manufPrice.push_back(manufacturingPrice);
		sellingPrice.push_back(selling);

		inp >> id;
		inp.ignore();
		getline(inp, item);
		inp >> ordered >> manufacturingPrice >> selling;
	}
}

// sorts all of the data
void sortData(vector<int>& itemID, vector<string>& itemName, vector<int>& pOrdered,
			  vector<int>& pInStore, vector<int>& pSold, vector<double>& manufPrice,
			  vector<double>& sellingPrice, int size)
{
	int idTemp, orderedTemp, inStoreTemp, soldTemp;
	string itemTemp;
	double manufTemp, sellingTemp;
	int iteration;
	int index;
	
	// sorts the items
	for (iteration = 1; iteration < size; iteration++)
	{
		for (index = 0; index < size - iteration; index++)
			if (itemName[index] > itemName[index + 1])
			{
				// id
				idTemp = itemID[index];
				itemID[index] = itemID[index + 1];
				itemID[index + 1] = idTemp;

				// item name
				itemTemp = itemName[index];
				itemName[index] = itemName[index + 1];
				itemName[index + 1] = itemTemp;

				// pieces ordered
				orderedTemp = pOrdered[index];
				pOrdered[index] = pOrdered[index + 1];
				pOrdered[index + 1] = orderedTemp;

				// pieces in store
				inStoreTemp = pInStore[index];
				pInStore[index] = pInStore[index + 1];
				pInStore[index + 1] = inStoreTemp;

				// pieces sold
				soldTemp = pSold[index];
				pSold[index] = pSold[index + 1];
				pSold[index + 1] = soldTemp;

				// manufacturing price
				manufTemp = manufPrice[index];
				manufPrice[index] = manufPrice[index + 1];
				manufPrice[index + 1] = manufTemp;

				// selling price
				sellingTemp = sellingPrice[index];
				sellingPrice[index] = sellingPrice[index + 1];
				sellingPrice[index + 1] = sellingTemp;
			}
	}
}

// Displays the menu
void displayMenu(vector<int>& itemID, vector<string>& itemName, vector<int>& pOrdered,
			  vector<int>& pInStore, vector<int>& pSold, vector<double>& manufPrice,
			  vector<double>& sellingPrice, int size)
{
	int menuNumber = 0;

	cout << showpoint << fixed << setprecision(2);

	cout << setw(60) << "Welcome to the Friendly Hardware Store!" << endl << endl;
	cout << "Choose among the following options:" << endl;
	cout << "1: To see if an item is in the store." << endl
			<<	"2: To buy an item." << endl
			<<	"3. To check the price of an item." << endl
			<<	"4: To print the inventory." << endl
			<<	"9: To end the program: ";
	cin >> menuNumber;
	cin.ignore();
	cout << endl;

	while (menuNumber != 9)
	{
		if (menuNumber == 1)
			inStore(itemName, pInStore, size);

		else if (menuNumber == 2)
			sellItem(itemName, pOrdered, pInStore, pSold, sellingPrice, size);

		else if (menuNumber == 3)
			checkPrice(itemName, sellingPrice, size);

		else if (menuNumber == 4)
		{
			print(itemID, itemName, pOrdered, pInStore, pSold, manufPrice,
				  sellingPrice, size);
		}

		else if (menuNumber == 9)
			cout << "Program by: Xavier Fox" << endl << endl;

		else
			cout << "Invalid number" << endl;

		cout << setw(60) << "Welcome to the Friendly Hardware Store!" << endl << endl;
		cout << "Choose among the following options:" << endl;
		cout << "1: To see if an item is in the store." << endl
			 <<	"2: To buy an item." << endl
			 <<	"3. To check the price of an item." << endl
			 <<	"4: To print the inventory." << endl
			 <<	"9: To end the program: ";
		cin >> menuNumber;
		cin.ignore();
		cout << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;
}

// Determines if the item is in the store
void inStore(vector<string> itemName, vector<int> pInStore, int size)
{
	string searchItem;
	int searchIndex;

	cout << "Enter the name of the item you wish to search for: ";
	getline(cin, searchItem);
	cout << endl;

	searchIndex = binarySearch(itemName, searchItem, size);
	
	if (searchIndex >= 0)
	{
		if (pInStore[searchIndex] == 0)
			cout << "We are currently out of stock" << endl << endl;
		else
			cout << searchItem << " is found in the store" << endl << endl;
	}
	else
		cout << searchItem << " is not found in the store" << endl << endl;
}

// Has the user buy an item
void sellItem(vector<string>& itemName, vector<int>& pOrdered, vector<int>& pInStore,
			  vector<int>& pSold, vector<double>& sellingPrice, int size)
{
	string searchItem;
	int searchIndex, quantity;
	char yesOrNo;

	cout << "Enter the name of the item: ";
	getline(cin, searchItem);

	searchIndex = binarySearch(itemName, searchItem, size);

	if (searchIndex >= 0 && pInStore[searchIndex] != 0)
	{
		cout << "Enter the quantity you wish to purchase: ";
		cin >> quantity;
		cout << endl;

		if (quantity <= pInStore[searchIndex])
		{
			cout << "Amount Due = $" << quantity * sellingPrice[searchIndex] << endl
				 << endl;

			pSold[searchIndex] += quantity;
			pInStore[searchIndex] = pInStore[searchIndex] - quantity;
		}
		else
		{
			cout << "Currently the store has only " << pInStore[searchIndex] << endl
				 << "Would you like to purchase that many (y/n): ";
			cin >> yesOrNo;
			cout << endl;

			if (yesOrNo == 'y')
			{
				cout << "Amount Due = $" 
					 << pInStore[searchIndex] * sellingPrice[searchIndex] << endl
					 << endl;

				pSold[searchIndex] += pInStore[searchIndex];
				pInStore[searchIndex] = 0;
			}
			else
				cout << "Please check with the manager for assistance" << endl << endl;
		}
	}
	else
	{
		cout << searchItem << " is not found in the store or we are out of stock"
		     << endl << endl;
	}
}

// Checks the price of the item
void checkPrice(vector<string> itemName, vector<double> sellingPrice, int size)
{
	string searchItem;
	int searchIndex;

	cout << "Enter the name of the item: ";
	getline(cin, searchItem);
	cout << endl;

	searchIndex = binarySearch(itemName, searchItem, size);

	if (searchIndex >= 0)
	{
		cout << "The price of the " << searchItem << " is: $"
		     << sellingPrice[searchIndex] << endl << endl;
	}
	else
		cout << searchItem << " is not found in the store" << endl << endl;
}

// prints the inventory of the hardware store
void print(vector<int> itemID, vector<string> itemName, vector<int> pOrdered,
		   vector<int> pInStore, vector<int> pSold, vector<double> manufPrice,
		   vector<double> sellingPrice, int size)
{
	int totalItems = 0;
	double totalInventory = 0.0;

	cout << setw(50) << "Friendly Hardware Store" << endl << endl;

	cout << "itemID itemName       pOrdered pInStore pSold manufPrice sellingPrice"
		 << endl;

	for (int i = 0; i < size; i++)
	{
		cout << setw(7) << left << itemID[i] << setw(15) << itemName[i] << right
			 << setw(8) << pOrdered[i] << setw(9) << pInStore[i] << setw(6)
			 << pSold[i] << setw(11) << manufPrice[i] << setw(13)
			 << sellingPrice[i] << endl;

		totalItems += pInStore[i];
		totalInventory += sellingPrice[i] * pInStore[i];
	}

	cout << endl << "Total Inventory: $" << totalInventory << endl
		 << "Total number of items in the store: " << totalItems << endl << endl;
}

// searches the array for the string item
int binarySearch(vector<string>& list, string searchItem, int size)
{
	int first = 0;
	int last = size - 1;
	int mid;
	bool found = false;
	
	while (first <= last && !found)
	{
		mid = (first + last) / 2;
		
		if (list[mid] == searchItem)
			found = true;
		else if (list[mid] > searchItem)
			last = mid - 1;
		else
			first = mid + 1;
	}
	
	if (found)
		return mid;
	else
		return -1;
}