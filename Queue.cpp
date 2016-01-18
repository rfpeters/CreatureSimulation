/*********************************************************************
** Author: Ryan Peters
** Date: 11/04/15
** Description: Class functions as a simple queue container.  There
**    are functions for adding and removing nodes
*********************************************************************/
#include "Queue.hpp"

/********************************************************************
** Description: Constructor, intializes size to zero, creates two 
**    empty nodes.
********************************************************************/
Queue::Queue()
{
	firstNode = 0;
	lastNode = firstNode;
	size = 0;
}

/********************************************************************
** Description: Destructor deletes the nodes in the queue.
********************************************************************/
Queue::~Queue()
{
	while (size > 0)
	{
		Node *tmpNode = firstNode;
		firstNode = firstNode->next;
		lastNode->next = firstNode;
		delete tmpNode;
	}
}

/********************************************************************
** Description: Gets the queue size
** Return: size
********************************************************************/
int Queue::getSize()
{
	return size;
}

/********************************************************************
** Description: Adds a node to the queue
** Param num: Data for the node
********************************************************************/
void Queue::add(Creature* creature)
{
	if (size == 0)
	{
		firstNode = new Node();
		firstNode->data = creature;
		lastNode = firstNode;
		firstNode->next = lastNode;
	}
	else
	{
		Node *oldLast = lastNode;
		lastNode = new Node();
		lastNode->data = creature;
		lastNode->next = 0;
		oldLast->next = lastNode;
	}
	
	size++;
}

/********************************************************************
** Description: Removes the front node from the queue
** Return: Data from the removed node
********************************************************************/
Creature* Queue::remove()
{
	if(size == 0)
	{
		return 0;
	}
	else
	{
		Creature* tmpData = firstNode->data;
		Node *tmpNode = firstNode;
		firstNode = firstNode->next;
		delete tmpNode;
		size--;
		return tmpData;
	}
}