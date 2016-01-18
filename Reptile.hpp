/********************************************************************
** Author: Ryan Peters
** Date: 11/07/15
** Description: Reptile People inherits from Creature class.  
**    Implements attackRoll, defenseRoll, and calcDamage functions.
********************************************************************/
#ifndef REPTILE_HPP
#define REPTILE_HPP

#include "Creature.hpp"

class Reptile: public Creature
{
private:
	Die attackDie1;
	Die attackDie2;
	Die attackDie3;
	Die defenseDie;
public:
	Reptile(std::string);
	int attackRoll();
	int defenseRoll();
	int calcDamage(int);
};
#endif