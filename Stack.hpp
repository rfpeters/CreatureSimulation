/*********************************************************************
** Author: Ryan Peters
** Date: 11/04/15
** Description: Class functions as a simple stack container.  There
**    are functions for adding and removing nodes
*********************************************************************/
#ifndef STACK_HPP
#define STACK_HPP

#include "Creature.hpp"

class Stack
{
private:
	/*Structure for stack nodes*/
	struct Node
	{
		Creature* data;
		Node *next;
	};
	Node *stackNode;
	int size;	
	
public:
	Stack();
	~Stack();
	int getSize();
	void add(Creature*);
	Creature* remove();
};
#endif