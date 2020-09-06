#include <stdio.h>
#include <stdlib.h>
#include <time.h>		//required for srand()

/**
 * Single Linked list implementation with numerous
 * operations.
 * author:  labgeek@gmail.com
 * date:  9/4/2020
 */
typedef struct Node {
	int data;			//for storing the data held in the linked list node
	struct Node* next;	//for storing the address of the immediate next node
}Node;

typedef struct {
	struct Node* head;	//address of the first node (NULL to start)
	struct Node* tail;	//address of the last node (NULL to start)
	int nodeCount;		//count of the total number of nodes
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
Node * find(LinkedList*, int, Node **);
int deleteFirst(LinkedList*);
int deleteLast(LinkedList*);
int deleteTarget(LinkedList*, int);
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
	printf("6.  Print list (Data only)\n");
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
Node * find(LinkedList* listptr, int target, Node **prvPtr) {
	
	Node* current = listptr->head; //gets address of current head address
	*prvPtr = NULL;
	while (current != NULL) {
		if (current->data == target) {
			break;
		}
		*prvPtr = current;
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

int deleteFirst(LinkedList* listptr) {
	if (listptr->nodeCount == 0) {
		return -99;
	}
	
	Node* first = listptr->head;
	int data = first->data;
	if (listptr->nodeCount == 1) {
		//there is only one node
		listptr->head = NULL;
		listptr->tail = NULL;
	}
	else {
		listptr->head = first->next;
	}
	free(first);
	listptr->nodeCount--;
	return data;
}


int deleteLast(LinkedList* listptr) {
	if (listptr->nodeCount == 0) {
		return -99;
	}

	/* Assign current address of current ptr to head */
	Node* current = listptr->head;
	//Access last node ptr
	Node* last = listptr->tail;
	int data = last->data;

	if (listptr->nodeCount == 1) {
		/* If there is only one node, the we need to delete that node
		so we must assign NULL to both head and tail pointer, as the linked list
		would be empty after this operation */
		listptr->head = NULL;
		listptr->tail = NULL;
	}
	/* If there are many nodes in linked list, we need
	to search for the second to last node and assign
	that one to tail*/
	else {
		/* as long as we don't get address of last tail node. iterate through */
		while (current->next != listptr->tail) {
			current = current->next;
		}
		/* update tail pointer */
		listptr->tail = current;
		listptr->tail->next = NULL;
	}
	free(last);
	listptr->nodeCount--;
	return data;
}

int deleteTarget(LinkedList* listptr, int target) {
	Node* current = NULL, * prev = NULL;
	current = find(listptr, target, &prev);
	if (current == NULL)
		return -99;

	int data = current->data;
	if (current == listptr->head)
		return deleteFirst(listptr);

	else if (current == listptr->tail)
		return deleteLast(listptr);

	else {
		prev->next = current->next;
		free(current);
		listptr->nodeCount--;
		return data;
	}
}

void reverse(LinkedList* listptr) {
	if (listptr->nodeCount <= 1) {
		return;
	}

	Node* p, * q, * r;
	q = NULL;
	p = listptr->head;
	r = p->next;
	while (1) {
		//reverse the linked list here
		p->next = q;
		if (p == listptr->tail) {
			break;
		}
		//shift the pointers toward the right
		q = p;
		p = r;
		r = r->next;
	}
	//swap the head and tail address
	listptr->tail = listptr->head;
	listptr->head = p;
}


int main()
{
	LinkedList list;
	initList(&list);
	int choice, data, success, n, target;
	menu();
	int quit = 0;
	Node* current = NULL, *prev = NULL;
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
		case 7:
			printf("Enter target to find: ");
			scanf("%d", &data);
			current = find(&list, data, &prev);
			if (current == NULL)
				printf("Target not found in the Linked List\n");
			else
				printf("Target exists, address of the target node: %p, previous: %p", current, prev);
			break;
		case 8:
			data = deleteFirst(&list);
			if (data == -99)
				printf("Linked list is empty\n");
			else
				printf("First node has been deleted, data:  %d\n", data);
			break;
		case 9:
			data = deleteLast(&list);
			if (data == -99)
				printf("Linked list is empty\n");
			else
				printf("First node has been deleted, data:  %d\n", data);
			break;
		case 10:
			printf("Enter target to find: ");
			scanf("%d", &target);
			data = deleteTarget(&list, target);
			if (data == -99)
				printf("Target %d does not exist in the list\n", target);
			else
				printf("Target node with data %d, deleted successfully\n", data);
			break;
		case 11:
			reverse(&list); //pass in list object
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
