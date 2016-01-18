/********************************************************************
** Author: Ryan Peters
** Date: 11/07/15
** Description: Shadow inherits from Creature class.  Implements
**    attackRoll, defenseRoll, and calcDamage functions.
********************************************************************/
#ifndef SHADOW_HPP
#define SHADOW_HPP

#include "Creature.hpp"
#include <iostream>
#include <stdlib.h>

class Shadow: public Creature
{
private:
	Die attackDie1;
	Die attackDie2;
	Die defenseDie;
	bool special;
public:
	Shadow(std::string);
	int attackRoll();
	int defenseRoll();
	int calcDamage(int);
};
#endif