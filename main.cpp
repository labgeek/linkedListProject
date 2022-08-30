#include <cstdlib>
#include "List.h";
#include <iostream>
#include <ctime>   // for time()
using namespace std;

/*
simple node adding to linked list
*/
int main()
{
	List link;
	link.addNode(3);
	link.addNode(5);
	link.addNode(7);
	link.addNode(8);
	link.addNode(9);

	link.PrintList();
	link.deleteNode(3);
	link.PrintList();
  return 0;
}
