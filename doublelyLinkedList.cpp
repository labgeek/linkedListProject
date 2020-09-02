/*****************************************************************//**
 * \file   dll.cpp
 * \brief  
 * Simple implementation of a doublely linked list
 * labgeek@gmail.com
 * 
 * \date   9/2/2020
 *********************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

void traverseForward(node* head); //start at first node, print till end of last node in list
void traverseBackwards(node* head); //start at tail node, print till end of first node in list

int main()
{


	node* head; //front of our dll
	node* tail; //end of our dll
	node* n; //help us build our linked list

	/*
	Manually creating each node for test purposes
	*/
	n = new node;
	n->data = 1;
	n->prev = NULL;  //previous pointer pointing to nothing
	head = n;
	tail = n;

	n = new node;
	n->data = 2;
	n->prev = tail;
	tail->next = n;
	tail = n;

	n = new node;
	n->data = 3;
	n->prev = tail;
	tail->next = n;
	tail = n;

	n = new node;
	n->data = 4;
	n->prev = tail;
	tail->next = n;
	tail = n;
	tail->next = NULL;  //access next pointer which points to nothing
	traverseForward(head);
	traverseBackwards(tail);

	return 0;
}

void traverseForward(node* head) {
	node* temp = head; //temp point to first node

	while (temp != NULL) { //make sure its pointing to something
		cout << temp->data << " ";
		temp = temp->next; //temp ptr points to next node in list
	}
	cout << endl;
}

void traverseBackwards(node* tail) {
	node* temp = tail; //temp point to last node

	while (temp != NULL) { //make sure its pointing to something
		cout << temp->data << " ";
		temp = temp->prev; //temp ptr points to next node in list
	}
	cout << endl;

}
