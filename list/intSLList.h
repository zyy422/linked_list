#ifndef INTSLLIST_H_
#define INTSLLIST_H_

class IntSLLNode
{
public:
	IntSLLNode():next(0){};
	IntSLLNode(int el, IntSLLNode* ptr = 0) :info(el), next(ptr){};

public:	
	int info;
	IntSLLNode *next;
	//	friend class IntSLLList;
};

class IntSLLList
{
public:
	IntSLLList():head(0), tail(0){};
	void addToHead(int el);
	void addToTail(int el);
	int deleteFromHead();	//delete node and return its values
	int deleteFromTail();
	void deleteNode(int el);	
	bool isInList(int el);	//judge whether the node is in the linked list
private:
	IntSLLNode *head,*tail;
};

#endif