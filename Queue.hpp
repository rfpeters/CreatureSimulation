/*********************************************************************
** Author: Ryan Peters
** Date: 11/04/15
** Description: Class functions as a simple queue container.  There
**    are functions for adding and removing nodes
*********************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Creature.hpp"

class Queue
{
private:
	/*Structure for nodes*/
	struct Node
	{
		Creature* data;
		Node *next;
	};
	Node *firstNode;
	Node *lastNode;
	int size;
public:
	Queue();
	~Queue();
	int getSize();
	void add(Creature*);
	Creature* remove();
};
#endif