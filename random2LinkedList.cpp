#include <iostream>
#include <time.h>
using namespace std;
/**
 * @author JD Durick
 * Date:  8/12/2020
 * Email:  labgeek@gmail.com
 * Description:  Was bored and saw this Assignement and figured I would do it for fun.
 * https://www2.hawaii.edu/~walbritt/ics212/assignments/assignment19.htm
 */
class LinkedList {
private:
	typedef struct node {
		int data; //data data member (hold int)
		node* next; //create a node pointer in each node
	} *nodePtr;

	//typedef struct node* nodePtr; //uses nodePtr same as struct node*
	nodePtr head;
	nodePtr current;
	nodePtr temp;

public:
	LinkedList(); //Constructor
	void addRandomNumber(int addData);
	int getNodeCount();
	int getSumValue();
};

/**
 * Constructor LinkedList.
 * 
 */
LinkedList::LinkedList() {
	head = NULL;
	current = NULL;
	temp = NULL;
}

/**
 * Add new nodes to the linked list which in this case is
 * random digits created.
 * 
 * \param addData
 */
void LinkedList::addRandomNumber(int addData) {
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

/**
 * gets the total number of nodes in the linked list.
 * 
 * \return 
 */
int LinkedList::getNodeCount() {
	current = head;
	int counter = 0;
	cout << "The List is: ";
	while (current != NULL)
	{
		cout << current->data << ", ";
		current = current->next; //advance the pointer
		counter++;
	}
	return counter;
}
/**
 * Gets the total sum values of all the random digits 
 * within the linked list.
 * 
 * \return 
 */
int LinkedList::getSumValue() {
	current = head;
	int totalSumValue = 0;
	while (current != NULL)
	{
		totalSumValue += current->data;
		current = current->next; //advance the pointer
	}
	return totalSumValue;
}

/**
 * Gets the average of the total sum / nodes.
 * 
 * \param totalnum
 * \param sum
 * \return 
 */
double getAverage(double totalnum, double sum) {
	double avg = 0.0;
	avg = sum / totalnum;
	return avg;
}

/**
 * Populates the array with random numbers.
 * 
 * \param sizearray
 * \param r
 * \return 
 */
int* populate(int sizearray, int r[]) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < sizearray; i++)
		r[i] = (rand() % 100);
	return r;
}

/**
 * Driver program.
 * 
 * \return 
 */
int main()
{
	LinkedList llObj;
	int size_of_array = 3;
	int randArray[11] = {0};
	int* ptr = NULL;
	int totalNodes, tSum = 0;
	double average = 0.0;
	ptr = populate(size_of_array, randArray);
	for (int i = 0; i < size_of_array; i++)
		llObj.addRandomNumber(*(ptr + i));

	totalNodes = llObj.getNodeCount();
	tSum = llObj.getSumValue();
	cout << endl << "Count: " << totalNodes << endl;
	cout << "Sum: " << tSum << endl;
	average = getAverage(totalNodes, tSum);
	cout << "Average: " << average << endl;
	return 0;
}
