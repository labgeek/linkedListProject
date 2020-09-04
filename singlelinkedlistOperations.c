#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Single Linked list implementation with numerous
 * operations.
 */
typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct {
	struct Node* head;
	struct Node* tail;
	int nodeCount;
} LinkedList;

/**
 * Prototype declarations
 */

void initList(LinkedList*);
void createListRandomNumbers(LinkedList*);
void insertAtHead(LinkedList*, int);
void insertAtTail(LinkedList*, int);
void printListDetail(LinkedList*);
void printList(LinkedList*);
Node * find(LinkedList*, int);
void deleteFirst(LinkedList*);
void deleteLast(LinkedList*);
void deleteTarget(LinkedList*, int);
void reverse(LinkedList*);
int loadFromFile(LinkedList*, char*);

void menu() {
	printf("    Singly Linked list Operations\n");
	printf("----------------------------------\n");
	printf("1.  Load from file\n");
	printf("2.  Create list with Random Numbers\n");
	printf("3.  Insert at head\n");
	printf("4.  Insert at tail\n");
	printf("5.  Print list (detail)\n");
	printf("6.  Print list (Data)\n");
	printf("7.  Find\n");
	printf("8.  Delete First\n");
	printf("9.  Delete Last Node\n");
	printf("10.  Delete target node\n");
	printf("11. Reverse linked list\n");
	printf("12. Quit\n");
	return;
}
/**
 * Initialize linked list object.
 * 
 * \param listptr
 */
void initList(LinkedList* listptr)
{
	listptr->head = NULL;
	listptr->tail = NULL;
	listptr->nodeCount = 0;

}

void insertAtHead(LinkedList* listptr, int data) {
	Node* newNodePtr = (Node*)malloc(sizeof(Node));
	if (newNodePtr == NULL) {
		printf("Unable to allocate new Node\n");
		return;
	}

	newNodePtr->data = data;
	newNodePtr->next = NULL;

	if (listptr->nodeCount == 0) {
		//this is the case where the list is empty
		listptr->head = newNodePtr;
		listptr->tail = newNodePtr;
	}
	/**
	 * Add data element to head of linked list.
	 */
	else {
		//this is the case when the list is not empty
		newNodePtr->next = listptr->head;
		listptr->head = newNodePtr;
	}
	listptr->nodeCount++;



}
void insertAtTail(LinkedList* listptr, int data) {
	Node* newNodePtr = (Node*)malloc(sizeof(Node));
	if (newNodePtr == NULL) {
		printf("Unable to allocate new Node\n");
		return;
	}

	newNodePtr->data = data;
	newNodePtr->next = NULL;

	if (listptr->nodeCount == 0) {
		//this is the case where the list is empty
		listptr->head = newNodePtr;
		listptr->tail = newNodePtr;
	}
	else {
		//this is the case when the list is not empty
		listptr->tail->next = newNodePtr;
		listptr->tail = newNodePtr;
	}
	listptr->nodeCount++;
}

/**
 * printList - pass the address of listobject
 * 
 * \param listptr
 */
void printList(LinkedList* listptr) {
	if (listptr->nodeCount == 0) {
		printf("Linked List is empty!!");
		return;
	}
	
	Node* current = listptr->head; //getting address from head into current pointer
	while (current != NULL) {
		printf("%d\n", current->data); 
		current = current->next; //current->next is the address of the next node, jumping to next node address
	}
	
}

void printListDetail(LinkedList* listptr) { //print node data, address of each node
	if (listptr->nodeCount == 0) {
		printf("Linked List is empty!!");
		return;
	}

	printf("Printing linked list in details\n");
	printf("HEAD:  %p\n", listptr->head);
	int counter = 1;

	Node* current = listptr->head; //getting address from head into current pointer
	while (current != NULL) {
		printf("%d: (%p)[%d|%p]\n", counter, current, current->data, current->next);
		current = current->next; //current->next is the address of the next node, jumping to next node address
		counter++;
	}
	printf("TAIL:  %p\n", listptr->tail);
	return;


}

//linear searching
Node * find(LinkedList* listptr, int target) {
	Node* current = listptr->head; //gets address of current head address

	while (current != NULL) {
		if (current->data == target) {
			break;
		}
		current = current->next;
	}
	return current; //if nothing, would return NULL

}

int loadFromFile(LinkedList* listptr, char* filename) {
	FILE* inputfile = fopen(filename, "r");
	if (inputfile == NULL)
		return 0;
	int data;
	fscanf(inputfile, "%d", &data);
	while (!feof(inputfile)) { //true if feof entered
		insertAtTail(listptr, data);
		fscanf(inputfile, "%d", &data);
	}

	fclose(inputfile);
	return 1;

}


void createListRandomNumbers(LinkedList* listptr, int n)
{
	int i;
	srand(time(NULL));
	for (i = 1; i <= n; ++i) {
		int k = rand() % 1000;
		insertAtTail(listptr, k);
	}
}
int main()
{
	LinkedList list;
	initList(&list);
	int choice, data, success, n;
	menu();
	int quit = 0;
	while (!quit) {
		printf("Please enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1: 
			success = loadFromFile(&list, "testfile.txt");
			if (success == 1)
				printf("File has been loaded!!\n");
			else
				printf("Failed to open\n");
			break;

		case 2:
			printf("Number of random number to be added to linked list: ");
			scanf("%d", &n);
			createListRandomNumbers(&list, n);
			break;

		case 3:
			//ask for input
			printf("Input data to insert at head (first node): ");
			scanf("%d", &data);
			insertAtHead(&list, data);

			break;
		case 4:
			printf("Input data to insert at Tail (last node): ");
			scanf("%d", &data);
			insertAtTail(&list, data);
			break;
		case 5:
			printListDetail(&list);
			break;
		case 6:
			printList(&list);
			break;
		case 7:printf("Not implemented yet\n");
			break;
		case 8:printf("Not implemented yet\n");
			break;
		case 9:printf("Not implemented yet\n");
			break;
		case 10:printf("Not implemented yet\n");
			break;
		case 11:printf("Not implemented yet\n");
			break;
		case 12:printf("Not implemented yet\n");
			quit = 1;
			break;
		default:
			printf("Invalid option chosen, valid option is from 1-11\n");
		}

	}


	return 0;
}
