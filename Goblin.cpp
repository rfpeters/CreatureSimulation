/********************************************************************
** Author: Ryan Peters
** Date: 11/07/15
** Description: Goblin inherits from Creature class.  Implements
**    attackRoll, defenseRoll, and calcDamage functions.
********************************************************************/
#include "Goblin.hpp"

/********************************************************************
** Description: Constructor, intializes name, armorPoints,
**    strengthPoints, and achillesAttacked variables.
** Param t: Team the creature is on.
********************************************************************/
Goblin::Goblin(std::string t)
{
	name = "Goblin";
	team = t;
	armorPoints = 3;
	strengthPoints = 8;
	achillesAttacked = false;
}

/********************************************************************
** Description: Rolls two 6-side Die.  attackPoints is the sum of the
**    two rolls.  A roll of 12 activates Achilles special attack.
** Return: attackPoints
********************************************************************/
int Goblin::attackRoll()
{
	attackPoints = 0;
	
	attackPoints += attackDie1.rollResult();
	attackPoints += attackDie2.rollResult();
	
	if(attackPoints == 12 && achillesAttacked == false)
	{
		achillesAttacked = true;
		std::cout << "Goblin attacks " << opponent << " achilles." << std::endl;
	}
	
	return attackPoints;
}

/********************************************************************
** Description: Rolls one 6-side Die.  defensePoints is the result of
**    the roll.
** Return: defensePoints
********************************************************************/
int Goblin::defenseRoll()
{
	defensePoints = 0;
	
	defensePoints = defenseDie.rollResult();
	
	return defensePoints;
}

/********************************************************************
** Description: Calculates the damage taken in the turn.  The damage
**    is the opponents attackPoints minus the defensePoints.  If the 
**    Achilles attack was activated the opponents attack is halved.
** Param attack: Opponents attackPoints
** Return: damagePoints
********************************************************************/
int Goblin::calcDamage(int attack)
{
	damagePoints = 0;
	
	if(achillesAttacked && opponent.compare("Goblin") != 0)
	{
		attack /= 2;
	}
	
	if(attack - defensePoints >= 0)
	{
		damagePoints = (attack - defensePoints);
	}
	
	return damagePoints;
}

/********************************************************************
** Description: Regenerates the Goblin to full health.
********************************************************************/
void Goblin::regenerateStrength()
{
	strengthPoints = 8;
}