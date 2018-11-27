#include <iostream>
#include "intSLList.h"
using namespace std;

int main()
{	
	
	//primary realization single linked list 
	IntSLLNode *head = new IntSLLNode(10);
	head->next = new IntSLLNode(20);
	head->next->next = new IntSLLNode(30);
	head->next->next->next = new IntSLLNode(40);

	//create a new class to operate single linked list
	IntSLLList my_list;
	my_list.addToHead(20);
	my_list.addToHead(10);
	my_list.addToTail(30);
	my_list.addToTail(40);
	my_list.deleteNode(30);
	if (my_list.isInList(40))
	{
		cout << "Specified number not exist" << endl;
	}
	else
	{
		cout << "Sepcified number exists!" << endl;
	}

	return 0;
}
