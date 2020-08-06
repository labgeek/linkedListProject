class List {
private:
	/**
	 * Can only be accessed in Functions of class.
	 * 
	 */
	typedef struct node {
		int data; //data data member (hold int)
		node* next; //create a node pointer in each node
	} *nodePtr;

	//typedef struct node* nodePtr; //uses nodePtr same as struct node*
	nodePtr head;
	nodePtr current;
	nodePtr temp;

public:
	List(); //Constructor
	void addNode(int addData);
	void deleteNode(int delData);
	void PrintList();
};


#endif /* LIST_H_ */
