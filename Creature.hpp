/********************************************************************
** Author: Ryan Peters
** Date: 11/07/15
** Description: Base class for Creatures.  Has functions for getting 
**    the name, setting the opponent, getting the strength points, 
**    and applying the damage taken in combat.
********************************************************************/
#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>
#include<stdlib.h>
#include "Die.hpp"

class Creature
{
protected:
	std::string name;
	std::string opponent;
	std::string team;
	int attackPoints;
	int defensePoints;
	int armorPoints;
	int damagePoints;
	int strengthPoints;
public:
	/****************************************************************
	** Description: Gets the Creature's name.
	** Return: name
	****************************************************************/
	std::string getName()
	{
		return name;
	}
	
	/****************************************************************
	** Description: Set the opponent
	** Param op: name of the opponent
	****************************************************************/
	void setOpponent(std::string op)
	{
		opponent = op;
	}

	/****************************************************************
	** Description: Get the team
	** Return: team
	****************************************************************/
	std::string getTeam()
	{
		return team;
	}
	
	/****************************************************************
	** Description: Get the strength points
	** Return: strengthPoints
	****************************************************************/
	int getStrengthPoints()
	{
		if(strengthPoints < 0)
		{
			return 0;
		}
		else
		{
			return strengthPoints;
		}
	}
	
	/****************************************************************
	** Description: Subtracts the damage from the strength points
	****************************************************************/
	void applyDamage()
	{
		if(damagePoints - armorPoints > 0)
		{
			strengthPoints -= (damagePoints - armorPoints);
		}
	}

	/********************************************************************
	** Description: Regenerates the creatures health.
	********************************************************************/
	void regenerateStrength()
	{
		strengthPoints += rand() % 4 + 1;		
	}
	
	/*Abstract Functions for derived classes*/
	virtual int attackRoll() = 0;
	virtual int defenseRoll() = 0;
	virtual int calcDamage(int) = 0;
	
};
#endif