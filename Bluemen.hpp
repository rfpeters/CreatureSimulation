/********************************************************************
** Author: Ryan Peters
** Date: 11/07/15
** Description: Bluemen inherits from Creature class.  Implements
**    attackRoll, defenseRoll, and calcDamage functions.
********************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"

class Bluemen: public Creature
{
private:
	Die attackDie1;
	Die attackDie2;
	Die defenseDie1;
	Die defenseDie2;
	Die defenseDie3;
public:
	Bluemen(std::string);
	int attackRoll();
	int defenseRoll();
	int calcDamage(int);
};
#endif