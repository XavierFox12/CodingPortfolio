/***********************************************************
* Name:		Xavier Fox
*
* Email:	xf899715@ohio.edu
*
* File Name:	list1.h
*
* Description:	Header and implementation for the Lilist
*				class, which adds names into the list, shows
*				the entire list, searches through the list
*				for a specific name, and moves the first
*				item in the list to the back.
*
* Date:		2/15/17
*
* Lab #:	102
************************************************************/

#include <iostream>
#include <string>

struct Node{
	std::string data;
	Node *link;
};

class Lilist{
	public:
		Lilist(){head = NULL;}
		void add(std::string item);
		void show();
		Node* search(const std::string t);
		void move_front_to_back();

	private:
		Node *head;
};

//Adds the data into the list
void Lilist::add(std::string item){
	Node *tmp;
	if(head == NULL) {
		head = new Node;
		head -> data = item;
		head -> link = NULL;
	}
	else{
		for(tmp = head; tmp -> link != NULL; tmp = tmp -> link)
			;

		tmp -> link = new Node;
		tmp = tmp -> link;
		tmp -> data = item;
		tmp -> link = NULL;
	}
}

//Goes through the nodes and displays them on the screen
void Lilist::show() {
	for (Node *tmp = head; tmp != NULL; tmp = tmp -> link)
		std::cout << tmp -> data << " ";

	std::cout << '\n';
}

//Searches through the nodes for data that matches the target
Node* Lilist::search(const std::string t) {
	Node *cursor = head;

	for (cursor = head; cursor != NULL; cursor = cursor -> link)
	{
		if (cursor -> data == t)
			return cursor;
	}
	return NULL;
}

//Moves the first item in the list to the back
void Lilist::move_front_to_back() {
	Node *tmp, *cursor;

	tmp = head;
	head = head -> link;

	for (cursor = head; cursor -> link != NULL; cursor = cursor -> link)
		;

	cursor -> link = new Node;
	cursor = cursor -> link;
	cursor -> data = tmp -> data;
	cursor -> link = NULL;
}
