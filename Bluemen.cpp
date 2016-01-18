/********************************************************************
** Author: Ryan Peters
** Date: 11/07/15
** Description: Bluemen inherits from Creature class.  Implements
**    attackRoll, defenseRoll, and calcDamage functions.
********************************************************************/
#include "Bluemen.hpp"

/********************************************************************
** Description: Constructor, intializes name, armorPoints, and
**    strengthPoints variables.  Makes the attackDie 10-sided
** Param t: Team creature is on.
********************************************************************/
Bluemen::Bluemen(std::string t)
{
	name = "Bluemen";
	team = t;
	armorPoints = 3;
	strengthPoints = 12;
	attackDie1.setNumSides(10);
	attackDie2.setNumSides(10);
}

/********************************************************************
** Description: Rolls two 10-side Die.  attackPoints is the sum of 
**    the two rolls.
** Return: attackPoints
********************************************************************/
int Bluemen::attackRoll()
{
	attackPoints = 0;
	
	attackPoints += attackDie1.rollResult();
	attackPoints += attackDie2.rollResult();
	
	return attackPoints;
}

/********************************************************************
** Description: Rolls three 6-side Die.  defensePoints is the sum of 
**    the three rolls.
** Return: defensePoints
********************************************************************/
int Bluemen::defenseRoll()
{
	defensePoints = 0;
	
	defensePoints += defenseDie1.rollResult();
	defensePoints += defenseDie2.rollResult();
	defensePoints += defenseDie3.rollResult();
	
	return defensePoints;
}

/********************************************************************
** Description: Calculates the damage taken in the turn.  The damage
**    is the opponents attackPoints minus the defensePoints.
** Param attack: Opponents attackPoints
** Return: damagePoints
********************************************************************/
int Bluemen::calcDamage(int attack)
{
	damagePoints = 0;
	
	if(attack - defensePoints >= 0)
	{
		damagePoints = (attack - defensePoints);
	}
	
	return damagePoints;
}