/********************************************************************
** Author: Ryan Peters
** Date: 11/07/15
** Description: Goblin inherits from Creature class.  Implements
**    attackRoll, defenseRoll, and calcDamage functions.
********************************************************************/
#ifndef GOBLIN_HPP
#define GOBLIN_HPP

#include "Creature.hpp"
#include <iostream>

class Goblin: public Creature
{
private:
	Die attackDie1;
	Die attackDie2;
	Die defenseDie;
	bool achillesAttacked;
public:
	Goblin(std::string);
	int attackRoll();
	int defenseRoll();
	int calcDamage(int);
	void regenerateStrength();
};
#endif