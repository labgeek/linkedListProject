/*
 * List.cpp
 *
 *  Created on: Jul 20, 2020
 *  Author: labgeek@gmail.com
 */

#include <iostream>
#include <cstdlib>
#include "List.h";
using namespace std;

/**
 * Constructor.
 * 
 */
List::List() {
	head = NULL;
	current = NULL;
	temp = NULL;
}


void List::deleteNode(int delData) {
	nodePtr delPtr = NULL;  //node pointer set to NULL
	temp = head;
	current = head;
	while (current != NULL && current->data != delData) //traversed entire list
	{
		temp = current;
		current = current->next;
	}
	if (current == NULL)
	{
		cout << delData << " was not in the list\n";
		delete delPtr;
	}
	else {
		delPtr = current;
		current = current->next;
		temp->next = current;
		if (delPtr == head) {
			head = head->next;
			temp = NULL;
		}
		delete delPtr;
		cout << "The value " << delData << " was deleted\n";
	}

}


void List::addNode(int addData) {
	nodePtr n = new node;
	n->next = NULL;
	n->data = addData;

	if (head != NULL) { //pointer of our class, if head is pointing to object
		current = head;
		//check to see if at end of list
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = n;
	}
	else { //if we don't have a list
		// head will point to front
		head = n;
	}

}


void List::PrintList() {
	current = head;
	while (current != NULL)
	{
		cout << current->data << endl;
		current = current->next; //advance the pointer
	}

}
