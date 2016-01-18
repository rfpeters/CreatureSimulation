/********************************************************************
** Author: Ryan Peters
** Date: 11/07/15
** Description: Barbarian inherits from Creature class.  Implements
**    attackRoll, defenseRoll, and calcDamage functions.
********************************************************************/
#include "Barbarian.hpp"

/********************************************************************
** Description: Constructor, intializes name, armorPoints, and
**    strengthPoints variables.
** Param t: Team creature is on.
********************************************************************/
Barbarian::Barbarian(std::string t)
{
	name = "Barbarian";
	team = t;
	armorPoints = 0;
	strengthPoints = 12;
}

/********************************************************************
** Description: Rolls two 6-side Die.  attackPoints is the sum of the
**    two rolls.
** Return: attackPoints
********************************************************************/
int Barbarian::attackRoll()
{
	attackPoints = 0;
	
	attackPoints += attackDie1.rollResult();
	attackPoints += attackDie2.rollResult();
	
	return attackPoints;
}

/********************************************************************
** Description: Rolls two 6-side Die.  defensePoints is the sum of 
**    the two rolls.
** Return: defensePoints
********************************************************************/
int Barbarian::defenseRoll()
{
	defensePoints = 0;
	
	defensePoints += defenseDie1.rollResult();
	defensePoints += defenseDie2.rollResult();
	
	return defensePoints;
}

/********************************************************************
** Description: Calculates the damage taken in the turn.  The damage
**    is the opponents attackPoints minus the defensePoints.
** Param attack: Opponents attackPoints
** Return: damagePoints
********************************************************************/
int Barbarian::calcDamage(int attack)
{
	damagePoints = 0;
	
	if(attack - defensePoints >= 0)
	{
		damagePoints = (attack - defensePoints);
	}

	return damagePoints;
}