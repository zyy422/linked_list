#include "intSLList.h"

void IntSLLList::addToHead(int el)
{
	head = new IntSLLNode(el,head);	//head point moves to new increased node;
	if (tail == 0)
	{
		tail = head;
	}
}

void IntSLLList::addToTail(int el)
{	
	if (tail == 0)
	{
		tail = new IntSLLNode(el);
		head = tail;
	}
	tail->next = new IntSLLNode(el);
	tail = tail->next;		//tail point moves to new increased node
}

int IntSLLList::deleteFromHead()
{	
	int el = head->info;
	IntSLLNode *tmp = head->next; //create a temporary variable to save second node
	if (head == tail)
	{
		head = tail = 0;
	}
	else
	{
		delete head;	//here just delete data, the point name still exists;  
	}
	head = tmp;
	return el;
}

int IntSLLList::deleteFromTail()
{
	int el = tail->info;
	if (tail == head)
	{
		tail = head = 0;
	}
	else
	{
		for (IntSLLNode *i = head; i != tail;i=i->next)
		{
			if (i->next == tail)
			{	
				IntSLLNode *tmp = tail;
				tail = i;	//tail points to second last node
				delete tmp;	//delete last node
			}
		}
	}
	return el;
}

void IntSLLList::deleteNode(int el)
{
	if (head!=0)
	{
		if (tail == head && head->info == el)	//linked list only has one node and is be selected
		{
			delete head;
			head = tail = 0;
		}
		else
		{
			IntSLLNode *pred;
			for (pred = head; pred != tail;pred=pred->next)
			{
				if (pred->info == el && pred == head)		//first node
				{
					IntSLLNode *tmp = head->next;
					delete head;
					head = tmp;
				}
				else if (pred->next->info==el && pred->next == tail)	//last node
				{
					tail = pred;
					delete tail->next;
					tail->next = 0;
				}
				else
				{
					if (pred->next->info == el)		//node among the list
					{
						IntSLLNode *tmp = pred->next->next;
						delete pred->next;
						pred->next = tmp;
					}
				}
			}
		}
	}
}

bool IntSLLList::isInList(int el)
{
	IntSLLNode *tmp = head;
	for (tmp; tmp != tail->next; tmp = tmp->next)
	{
		if (tmp->info == el)
		{
			return true;
		}
	}
	return false;
}
