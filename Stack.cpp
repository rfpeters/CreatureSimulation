/********************************************************************
** Author: Ryan Peters
** Date: 11/04/15
** Description: Class functions as a simple stack container.  There
**    are functions for adding and removing nodes
********************************************************************/
#include "Stack.hpp"

/********************************************************************
** Description: Constructor, intializes size to zero and an empty 
**    node.
********************************************************************/
Stack::Stack()
{
	size = 0;
	stackNode = 0;
}

/********************************************************************
** Description: Destructor deletes the nodes in the stack.
********************************************************************/
Stack::~Stack()
{
	while (size > 0)
	{
		Creature* tmpData = stackNode->data;
		Node *tmpNode = stackNode;
		stackNode = stackNode->next;
		size--;
		delete tmpNode;
	}
}

/********************************************************************
** Description: Gets the stack size
** Return: size
********************************************************************/
int Stack::getSize()
{
	return size;
}

/********************************************************************
** Description: adds a node to the stack
** Param num: data for the node
********************************************************************/
void Stack::add(Creature* c)
{
	if (size == 0)
	{
		stackNode = new Node;
		stackNode->data = c;
	}
	else
	{
		Node *nextNode = new Node;
		nextNode->data = c;
		nextNode->next = stackNode;
		stackNode = nextNode;
	}
	size++;
}

/********************************************************************
** Description: Removes a node from the stack
** Return: data in the node that is removed
********************************************************************/
Creature* Stack::remove()
{
	if(size == 0)
	{
		return 0;
	}
	else
	{
		Creature* tmpData = stackNode->data;
		Node *tmpNode = stackNode;
		stackNode = stackNode->next;
		size--;
		delete tmpNode;
		return tmpData;
	}
}
	