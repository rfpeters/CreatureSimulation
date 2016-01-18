/********************************************************************
** Author: Ryan Peters
** Date: 11/07/15
** Description: Reptile People inherits from Creature class.  
**    Implements attackRoll, defenseRoll, and calcDamage functions.
********************************************************************/
#include "Reptile.hpp"

/********************************************************************
** Description: Constructor, intializes name, armorPoints, and
**    strengthPoints variables.
********************************************************************/
Reptile::Reptile(std::string t)
{
	name = "Reptile";
	team = t;
	armorPoints = 7;
	strengthPoints = 18;
}

/********************************************************************
** Description: Rolls three 6-side Die.  attackPoints is the sum of 
**	  the three rolls.
** Return: attackPoints
********************************************************************/
int Reptile::attackRoll()
{
	attackPoints = 0;
	
	attackPoints += attackDie1.rollResult();
	attackPoints += attackDie2.rollResult();
	attackPoints += attackDie3.rollResult();
	
	return attackPoints;
}

/********************************************************************
** Description: Rolls one 6-side Die.  defensePoints is the result of
**    the roll.
** Return: defensePoints
********************************************************************/
int Reptile::defenseRoll()
{
	defensePoints = 0;
	
	defensePoints += defenseDie.rollResult();
	
	return defensePoints;
}

/********************************************************************
** Description: Calculates the damage taken in the turn.  The damage
**    is the opponents attackPoints minus the defensePoints.
** Param attack: Opponents attackPoints
** Return: damagePoints
********************************************************************/
int Reptile::calcDamage(int attack)
{
	damagePoints = 0;
	
	if(attack - defensePoints >= 0)
	{
		damagePoints = (attack - defensePoints);
	}
	
	return damagePoints;
}