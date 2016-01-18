/********************************************************************
** Author: Ryan Peters
** Date: 11/07/15
** Description: Shadow inherits from Creature class.  Implements
**    attackRoll, defenseRoll, and calcDamage functions.
********************************************************************/
#include "Shadow.hpp"

/********************************************************************
** Description: Constructor, intializes name, armorPoints,
**    strengthPoints, and special variables.  Makes the attackDie 
**    10-sided.
********************************************************************/
Shadow::Shadow(std::string t)
{
	name = "Shadow";
	team = t;
	armorPoints = 0;
	strengthPoints = 12;
	attackDie1.setNumSides(10);
	attackDie2.setNumSides(10);
	special = false;
}

/********************************************************************
** Description: Rolls two 10-side Die.  attackPoints is the sum of 
**    the two rolls.
** Return: attackPoints
********************************************************************/
int Shadow::attackRoll()
{
	attackPoints = 0;
	
	attackPoints += attackDie1.rollResult();
	attackPoints += attackDie2.rollResult();
	
	return attackPoints;
}

/********************************************************************
** Decription: Calculates the defensePoints.  There is a 50/50 chance
**    of activatin the Shadow's special ability.  The special ability
**    allows the Shadow to dodge the attack.  If the attack is not 
**    dodged the defenseDie is rolled for the defensePoints.
** Return: defensePoints
********************************************************************/
int Shadow::defenseRoll()
{
	defensePoints = 0;
	
	if(rand() % 2 == 1)
	{
		special = true;
		std::cout << "The Shadow dodged the attack" << std::endl;
	}
	else
	{
		special = false;
		defensePoints += defenseDie.rollResult();
	}	
	
	return defensePoints;
}

/********************************************************************
** Description: Calculates the damage taken in the turn.  The damage
**    is the opponents attackPoints minus the defensePoints.  If 
**    special is activated no damage is taken.
** Param attack: Opponents attackPoints
** Return: damagePoints
********************************************************************/
int Shadow::calcDamage(int attack)
{
	damagePoints = 0;
	
	if(special)
	{
		return damagePoints;
	}
	else
	{
	
		if(attack - defensePoints >= 0)
		{
			damagePoints = (attack - defensePoints);
		}
		return damagePoints;
	}
}