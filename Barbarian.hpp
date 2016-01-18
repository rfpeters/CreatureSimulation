/********************************************************************
** Author: Ryan Peters
** Date: 11/07/15
** Description: Barbarian inherits from Creature class.  Implements
**    attackRoll, defenseRoll, and calcDamage functions.
********************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"

class Barbarian: public Creature
{
private:
	Die attackDie1;
	Die attackDie2;
	Die defenseDie1;
	Die defenseDie2;
public:
	Barbarian(std::string);
	int attackRoll();
	int defenseRoll();
	int calcDamage(int);
};
#endif