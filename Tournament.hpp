/********************************************************************
** Author: Ryan Peters
** Date: 11/19/15
** Description: Class is used to for running a tournament between 
**    two teams of Creatures.  Each creature is stored in a Queue.
********************************************************************/
#ifndef TROUNAMENT_HPP
#define TROUNAMENT_HPP

#include "Goblin.hpp"
#include "Barbarian.hpp"
#include "Reptile.hpp"
#include "Bluemen.hpp"
#include "Shadow.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include <string>
#include <limits>

class Tournament
{
private:
	int numberFighters;
	Queue team1;
	Queue team2;
	Stack allFighters;
	int team1Wins;
	int team2Wins;
public:
	Tournament();
	void setNumberFighters(int);
	void addFighterTeam1(Creature*);
	void addFighterTeam2(Creature*);
	Creature* getFighterTeam1();
	Creature* getFighterTeam2();
	void battle(Creature*, Creature*);
	bool checkEnd();
	std::string endGame();
	void displayResults(bool);
};
#endif