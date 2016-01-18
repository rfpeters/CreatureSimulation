/********************************************************************
** Author: Ryan Peters
** Date: 11/19/15
** Description: Class is used to for running a tournament between
**    two teams of Creatures.  Each creature is stored in a Queue.
********************************************************************/
#include "Tournament.hpp"

/********************************************************************
** Description: Constructor, creates null Queues for the teams.
********************************************************************/
Tournament::Tournament()
{
	team1Wins = 0;
	team2Wins = 0;
}

/********************************************************************
** Description: Sets the numer of fighters for each team.
** Param fighters: number of fighters
********************************************************************/
void Tournament::setNumberFighters(int fighters)
{
	numberFighters = fighters;
}

/********************************************************************
** Description: Adds a creature to Team 1.
** Param Creature*: Pointer to the creature
********************************************************************/
void Tournament::addFighterTeam1(Creature* c)
{
	team1.add(c);
}

/********************************************************************
** Description: Adds a creature to Team 2.
** Param Creature*: Pointer to the creature
********************************************************************/
void Tournament::addFighterTeam2(Creature* c)
{
	team2.add(c);
}

/********************************************************************
** Description: Gets the first creature from Team 1.
** Return: Pointer to the creature
********************************************************************/
Creature* Tournament::getFighterTeam1()
{
	return team1.remove();
}

/********************************************************************
** Description: Gets the first creature from Team 1.
** Return: Pointer to the creature
********************************************************************/
Creature* Tournament::getFighterTeam2()
{
	return team2.remove();
}

/********************************************************************
** Description: Controls the fight between two Creatures.
** Param combatant_1: Creature from Team 1
** Param combatant_2: Creature from Team 2
********************************************************************/
void Tournament::battle(Creature* combatant_1, Creature* combatant_2)
{
	int attack;
	int defense;
	int round = 1;
	
	combatant_1->setOpponent(combatant_2->getName());
	combatant_2->setOpponent(combatant_1->getName());
	
	do
	{
		std::cout << "Round: " << round++ << std::endl;
		std::cout << "+------------------------------+" << std::endl;
		
		/*Combatant_1 attack, Combatant_2 defend*/
		std::cout << "Combatant 1: " << combatant_1->getName() << " Attacks" << std::endl;
		attack = combatant_1->attackRoll();
		defense = combatant_2->defenseRoll();
		combatant_2->calcDamage(attack);
		combatant_2->applyDamage();
		std::cout << "Attack Points: " << attack << std::endl;
		std::cout << "Defense Points: " << defense << std::endl;
		std::cout << "Combatant 2 " << combatant_2->getName() 
		          << " Strength: " << combatant_2->getStrengthPoints() << std::endl;
		
		/*Combatant_1 defend, Combatant_2 attack*/
		if(combatant_1->getStrengthPoints() > 0 && combatant_2->getStrengthPoints() > 0)
		{
			std::cout << "Combatant 2: " << combatant_2->getName() << " Attacks" << std::endl;
			attack = combatant_2->attackRoll();
			defense = combatant_1->defenseRoll();
			combatant_1->calcDamage(attack);
			combatant_1->applyDamage();
			std::cout << "Attack Points: " << attack << std::endl;
			std::cout << "Defense Points: " << defense << std::endl;
			std::cout << "Combatant 1 " << combatant_1->getName() 
					  << " Strength: " << combatant_1->getStrengthPoints() << std::endl;
		}
		std::cout << std::endl;
		
		/*Pause between rounds*/
		if(combatant_1->getStrengthPoints() > 0 && combatant_2->getStrengthPoints() > 0)
		{
			std::cout << "Press ENTER to start next round..." << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}while(combatant_1->getStrengthPoints() > 0 && combatant_2->getStrengthPoints() > 0);
	
	/*Display winner of the fight*/
	if(combatant_1->getStrengthPoints() > 0)
	{
		std::cout << "Combatant 1:" << combatant_1->getName() << " Wins" << std::endl;
		std::cout << "Combatant 2:" << combatant_2->getName() << " Loses" << std::endl;
		std::cout << std::endl;
		combatant_1->regenerateStrength();
		team1.add(combatant_1);
		allFighters.add(combatant_2);
		team1Wins++;
	}
	else
	{
		std::cout << "Combatant 2:" << combatant_2->getName() << " Wins" << std::endl;
		std::cout << "Combatant 1:" << combatant_1->getName() << " Loses" << std::endl;
		std::cout << std::endl;
		combatant_2->regenerateStrength();
		team2.add(combatant_2);
		allFighters.add(combatant_1);
		team2Wins++;
	}

	std::cout << std::endl;
}

/********************************************************************
** Description: Checks if the teams has defeated all the creatures
**    from the other team.
** Return: True one of the teams has defeated all the fighters from
**    the other team, False both teams still have fighters.
********************************************************************/
bool Tournament::checkEnd()
{
	if (team1.getSize() == 0 || team2.getSize() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/********************************************************************
** Description: Adds remaining fighters from the winners team to the 
**    stack of all fighters. Returns the winning team.  If the wins
**    are equal the winner is determined by the last team standing.
** Return: Winning team.
********************************************************************/
std::string Tournament::endGame()
{
	if (team1Wins == team2Wins)
	{
		if (team1.getSize() > 0)
		{
			while (team1.getSize() > 0)
			{
				allFighters.add(team1.remove());
			}

			return "Team 1";
		}
		else if (team2.getSize() > 0)
		{
			while (team2.getSize() > 0)
			{
				allFighters.add(team2.remove());
			}

			return "Team 2";
		}
	}
	else if (team1Wins > team2Wins)
	{
		while (team1.getSize() > 0)
		{
			allFighters.add(team1.remove());
		}

		return "Team 1";
	}
	else if (team2Wins > team1Wins)
	{
		while (team2.getSize() > 0)
		{
			allFighters.add(team2.remove());
		}

		return "Team 2";
	}
}

/********************************************************************
** Description: Displays the results of the tournament.
********************************************************************/
void Tournament::displayResults(bool fullList)
{
	int place = 1;

	if (fullList)
	{
		while (allFighters.getSize() > 0)
		{
			Creature* c = allFighters.remove();
			if (place == 1)
			{
				std::cout << "1st Place: " << c->getName() << ": " << c->getTeam() << std::endl;
			}
			else if (place == 2)
			{
				std::cout << "2nd Place: " << c->getName() << ": " << c->getTeam() << std::endl;
			}
			else if (place == 3)
			{
				std::cout << "3rd Place: " << c->getName() << ": " << c->getTeam() << std::endl;
			}
			else
			{
				std::cout << c->getName() << ": " << c->getTeam() << std::endl;
			}
			place++;
		}
	}
	else
	{
		while (place <= 3)
		{
			Creature* c = allFighters.remove();
			if (place == 1)
			{
				std::cout << "1st Place: " << c->getName() << ": " << c->getTeam() << std::endl;
			}
			else if (place == 2)
			{
				std::cout << "2nd Place: " << c->getName() << ": " << c->getTeam() << std::endl;
			}
			else if (place == 3)
			{
				std::cout << "3rd Place: " << c->getName() << ": " << c->getTeam() << std::endl;
			}

			place++;
		}
	}
}