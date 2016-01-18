/*********************************************************************
** Author: Ryan Peters
** Date: 09/29/15
** Description: Die class is used for rolling a die
*********************************************************************/
#include "Die.hpp"
#include<stdlib.h>


/********************************************************************
** Description: Constructor sets numSides to 6
********************************************************************/
Die::Die()
{
	numSides = 6;
}

/********************************************************************
** Description: Constructor sets numSides to parameter sides
********************************************************************/
Die::Die(int sides)
{
	numSides = sides;
}

/********************************************************************
** Description: Set the number of sides
** Param sides: number of sides for the die
********************************************************************/
void Die::setNumSides(int sides)
{
	numSides = sides;
}

/********************************************************************
** Description: Uses rand() to simulate the roll of a die
** Return: Result of the rolls
********************************************************************/
int Die::rollResult()
{
	return rand() % numSides + 1;
}